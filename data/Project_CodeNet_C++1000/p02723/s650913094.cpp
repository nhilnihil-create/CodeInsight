#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	
	if(s[2] == s[3] && s[4] == s[5]) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}