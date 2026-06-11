// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

string removeExceptParens(string);
bool isBalancedParens(string);

int main() {
	vector<string> lines;
	while (true) {
		string line = "";
		getline(cin, line);
		if (line == ".") {
			break;
		}
		lines.push_back(line);
	}

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++) {
		string parenRemovedLine = removeExceptParens(*it);
		if (isBalancedParens(parenRemovedLine)) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}

string removeExceptParens(string str){
	string result = "";	
	for (string::iterator it = str.begin(); it != str.end(); it++) {
		if (*it == '(' || *it == ')' || *it == '[' || *it == ']') {
			result += *it;
		}
	}
	return result;
}

bool isBalancedParens(string str) {
//	cout << str << endl;
	if (str == "") {
		return true;
	}
	else {
		string::size_type paren1 = str.rfind("()");
		string::size_type paren2 = str.rfind("[]");
		if (paren1 == string::npos && paren2 == string::npos) {
			return false;
		}
		else {
			if (paren1 != string::npos) {
				str.replace((int)paren1, 2, "");
			}
			else if (paren2 != string::npos) {
				str.replace((int)paren2, 2, "");
			}
			return isBalancedParens(str);
		}
	}
}