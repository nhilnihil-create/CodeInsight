#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if(s[0] == s[1] && s[2] == s[3] && s[0] != s[2]) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}