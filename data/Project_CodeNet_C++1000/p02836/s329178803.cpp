#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

string s;

void solve() {
	cin >> s;
	int ans = 0, n = s.size();
	for(int i=0; i<n/2; i++) if(s[i] != s[n-i-1]) ans++;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

