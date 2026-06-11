#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array
 
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (s[2]==s[3] && s[4]==s[5]) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
		break;
	}
	return 0;
}
