#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

string s;

void solve() {
	cin >> s;
	int n = (int)s.size();
	int ok = 1;
	for(int i=0; i < n/2 && ok; i++) {
		if(s[i] != s[n/2-i-1] || s[i] != s[n/2+i+1] || s[i] != s[n-i-1]) ok = 0;
	}
	if(ok) cout << "Yes\n";
	else cout << "No\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

