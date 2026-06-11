// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'U' || s[i] == 'D') continue;
		if( !(i&1) && s[i] != 'R') {
			cout << "No";
			exit(0);
		}

		if( (i&1) && s[i] != 'L') {
			cout << "No";
			exit(0);
		}
	}
	
	cout << "Yes";


	return 0;
}
