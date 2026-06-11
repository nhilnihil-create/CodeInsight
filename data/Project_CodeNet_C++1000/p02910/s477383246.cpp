#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define MULTI_TEST



void solve() {
	string s;
	cin >> s;
	int ok = 1;
	for(int i=0; i<s.size(); i++) {
		if(i&1) {
			if(s[i] == 'R') ok = 0;
		} else {
			if(s[i] == 'L') ok = 0; 
		}
	}
	if(ok) cout << "Yes";
	else cout << "No";
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
#ifdef MULTI_TEST
	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
#else
	solve();
	cout << "\n";
#endif

	return 0;
}
