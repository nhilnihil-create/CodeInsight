/*
 * Ring.cpp
 *
 *  Created on: 2014/07/27
 *      Author: WanWan1985
 */
#include <iostream>
#include <string>
using namespace std;

int main(void) {


	string strS;
	getline(cin, strS);
	strS += strS;

	string strP;
	getline(cin, strP);

	if (strS.find(strP) == string::npos) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}

	return 0;
}