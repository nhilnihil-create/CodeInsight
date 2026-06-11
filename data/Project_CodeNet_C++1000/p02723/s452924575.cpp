#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

string s;

void solve() {
	cin >> s;
	if(s[2] == s[3] && s[4] == s[5]) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

