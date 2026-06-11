#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	string s;
	cin >> s;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == s[i - 1]) {
			cout << "Bad\n";
			return;
		}
	}
	cout << "Good\n";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}