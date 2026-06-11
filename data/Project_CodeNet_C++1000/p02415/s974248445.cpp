/*
 * TogglingCases.cpp
 *
 *  Created on: 2014/07/27
 *      Author: WanWan1985
 */
#include <iostream>
#include <cctype>
using namespace std;

int main(void) {

	string strInput = "";
	getline(cin, strInput);

	for (unsigned int i = 0; i < strInput.size(); i++) {

		char ch = strInput.at(i);
		if (islower(ch)) {			// 小文字
			ch = toupper(ch);
		} else if (isupper(ch)) {	// 大文字
			ch = tolower(ch);
		}
		cout << ch;
	}
	cout << endl;

	return 0;
}