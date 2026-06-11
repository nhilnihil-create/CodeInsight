#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 1) {
			if (s[i] == 'L' || s[i] == 'U' || s[i] == 'D') {
			     continue;	
			}
			else {
				cout << "No" << "\n";
				return 0;
			}
		}
		else {
			if (s[i] == 'R' || s[i] == 'U' || s[i] == 'D') {
				continue;
			} 
			else {
				cout << "No" << "\n";
				return 0; 
			}
		}
	}
	cout << "Yes" << "\n";
	return 0;
}