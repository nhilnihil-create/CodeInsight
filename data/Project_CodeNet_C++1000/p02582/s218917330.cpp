#include<iostream>
#include<string>

using namespace std;


int main() {

	string s;

	cin >> s;
	int ans;
	if (s[0] == 'R' && s[1] == 'R' && s[2] == 'R') {
		ans = 3;
	}
	else if ((s[0] == 'R' && s[1] == 'R')  || (s[1] == 'R' && s[2] == 'R')) {
		ans = 2;

	}
	else if (s[0] == 'R' || s[1] == 'R' || s[2] == 'R') {
		ans = 1;
	}
	else {
		ans = 0;
	}

	cout << ans << endl;

	return 0;
}