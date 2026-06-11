

#include<iostream>
#include<string>
using namespace std;


int main() {
	string s;
	cin >> s;

	bool ok = false;

	if (s[0] == s[1] && s[2] == s[3] &&s[0]!=s[2]) {
		ok = true;
	}
	else if (s[0] == s[2] && s[1] == s[3] && s[0]!=s[1]) {
		ok = true;
	}
	else if (s[0] == s[3] && s[1] == s[2] && s[0]!=s[1]) {
		ok = true;
	}
	else {
		ok = false;
	}

	if (ok) {
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
}
	return  0;
}