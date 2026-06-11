#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

string str;

bool solve(int p, char c) {
	for (int i = p+1; i < str.size(); i++) {
		if (str[i] == ']' || str[i] == ')') {
			if (str[i] == c) {
				str[p] = str[i] = ' ';
				return 1;
			} else {
				break;
			}
		} else if (str[i] == '(' || str[i] == '[') {
			char t = (str[i] == '(' ? ')' : ']');
			if (!solve(i, t)) {
				break;
			}
		}
	}
	return 0;
}

int main()
{	
	while (getline(cin, str), str != ".") {
		bool f = 0;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') {
				f = 1;
				char t = (str[i] == '(' ? ')' : ']');
				if (solve(i, t)) f = 0;
			} else if (str[i] == ')' || str[i] == ']') f = 1;
			if (f) break;
		}
		if (!f) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}