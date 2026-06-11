#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	bool ans = false;
	for(int i = 0; i < s.size() - 1; i++) {
		if(s[i] == s[i + 1]) {
			ans = true;
			break;
		}
	}
	if(ans) {
		cout << "Bad";
	} else {
		cout << "Good";
	}
}		

