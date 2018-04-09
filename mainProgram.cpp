#include "ProjectType.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

void administratorMenu();
void moderatorMenu();


int main() {

	vector<projectType> projectDatabase; //Database that holds all project objects

	//Indexing variable(s)
	int c;
	map<string, string>::iterator itr;
	
	//Menu Variables
	char loginMenu;
	
	char adminMenu;
	char moderatorMenu;


	char projectMenu;
	char menuIndex;
	
	//File IO Variables
	ifstream readProject;
	ofstream writeProject;

	//Temporary Project File
	projectType *tempProject;


	//User variables
	map<string, string> adminMap;
	map<string, string> modMap;
	
	//map<string, int> maintenanceMap;
	//map<string, int> maintenancePassMap;
	
	string username;
	string password;
	bool userCorrect;
	bool moderator;


	//make_heap(projectDatabase.begin(), projectDatabase.end(), projectType::getPriority); //Converts the project database into a max-heap
	
	readProject.open("Projects.txt");
	c = 0;
	while (!readProject.eof() && c < projectDatabase.size()) {
		tempProject = new projectType;
		readProject >> *tempProject;
		projectDatabase.push_back(*tempProject);
		//push_heap(projectDatabase.begin(), projectDatabase.end());
	}
	readProject.close();

	//In this segment of code I'm inserting a new admin-user into the
	//username and password hash tables
	adminMap.insert(pair<string, string>("Admin", "password")); 
	modMap.insert(pair<string, string>("Moderator", "password"));


	//The following function asks the user for their username and password,
	//and then matches the combination with the specified account
	
	do {

		moderator = false;
		userCorrect = false;

		cin.clear();
		cout << "Username: ";
		getline(cin, username);
		cin.clear();
		cout << "Password: ";
		getline(cin, password);

		itrAdmin = adminMap.find(username);
		
		if (itrAdmin == adminMap.end()) {
			
			itrMod = modMap.find(username);
	
			if (itrMod != modMap.end() && itrMod->second == password) {
				moderator = true;
				userCorrect = true;
			}
		}
		else
			if (itrAdmin->second == password)
				userCorrect = true;

		if (userCorrect == false) 
			cout << "Wrong username or password" << endl;
		
	} while (userCorrect == 0);


	//The segment of code that follows the login takes the user 
	//through their respective menus
	if (moderator == true) {
		moderatorMeu();
		cin >> moderatorMenu;
	}
	else {
		administratorMenu();
		cin >> administratorMenu;

	}



	return 0;
}

void administratorMenu() {

	cout << "Administrator Master Menu" << endl
		<< "I  - Inbox" << endl
		<< "P  - List all projects" << endl
		<< "================================" << endl
		<< "iP - Manage project 'i'" << endl
		<< "i+ - Increase project i's priority" << endl
		<< "================================" << endl
		<< "M  - Display this menu again" << endl
		<< "Q  - Exit menu" << endl;

}

void projectMenu() {

	cout << "Admin Project Menu" << endl
		<< "P  - Display project information" << endl
		<< "T  - Enter tool menu" << endl
		<< "N  - Edit Name " << endl
		<< "D  - Edit Description" << endl
		<< "================================" << endl
		<< "A  - Abandon Project" << endl
		<< "C  - Complete Projet" << endl
		<< "Q  - Return" << endl;

}

void toolMenu() {
	cout << "Admin Tool Menu" << endl
		<< "P  - List all tools" << endl
		<< "A  - Add tool" << endl
		<< "Di - Dismiss tool 'i'" << endl
		<< "Mi - Tool 'i' needs maintenance" << endl
		<< "Q  - Return" << endl;
		
}

void moderatorMenu() {

	cout << "Maintenance Master Menu" << endl
	<< "M  - Maintenance List" << endl
	<< "Mi - Tool 'i' needs maintenance" << endl
	<< "Ri - Tool 'i' has been repaired" << endl
	<< "Di - Mark tool 'i' for dismissal" << endl
	<< "Q  - Return" << endl;

}

