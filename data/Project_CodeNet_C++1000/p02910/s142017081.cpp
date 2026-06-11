#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
bool playable;
int32_t main() {
	playable = true; 
	cin >> s;
	for(int i = 0; i < s.length(); ++i) {
		if (i % 2 == 0) {
			if (s[i] == 'R' || s[i] == 'D' || s[i] == 'U') {
				continue;
			}
			else {
				playable = false;
				break;
			}
		} 
		if (i % 2 == 1) {
			if (s[i] == 'L' || s[i] == 'D' || s[i] == 'U') {
				continue;
			}
			else {
				playable = false;
				break;
			}
		} 
	}
	cout << ((playable) ? "Yes" : "No");
}