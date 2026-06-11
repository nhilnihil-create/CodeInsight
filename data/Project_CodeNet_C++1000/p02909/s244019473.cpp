#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define MULTI_TEST

void solve() {
	string s;
	cin >> s;
	if(s[0] == 'S') cout << "Cloudy";
	else if(s[0] == 'C') cout << "Rainy";
	else cout << "Sunny";
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
