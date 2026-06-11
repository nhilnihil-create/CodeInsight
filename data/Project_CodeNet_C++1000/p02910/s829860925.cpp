#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	string s;
	cin >> s;
	string ekey = "RUD", okey = "LUD";
	for(int i = 0; i <s.length(); i++) {
		if(i % 2 == 0 && ekey.find(s[i]) == string::npos) {
			cout << "No";
			return;
		}
		if(i % 2 == 1 && okey.find(s[i]) == string::npos) {
			cout << "No";
			return;
		}
	}
	cout << "Yes";

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}