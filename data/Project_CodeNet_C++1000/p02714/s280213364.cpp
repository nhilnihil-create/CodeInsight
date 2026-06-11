 // In the name of GOD
 
#include <bits/stdc++.h>
#define ll long long
#define pp pair <int, int>
using namespace std;
const int N = 1e5 + 10;
string s;
int n;

void solve() {
	cin >> n;
	cin >> s;
	vector <int> sufR(n), sufG(n), sufB(n);

	for (int i = n - 1; i >= 0; --i) {
		sufR[i] += (s[i] == 'R') + (i == n - 1 ? 0 : sufR[i + 1]);
		sufG[i] += (s[i] == 'G') + (i == n - 1 ? 0 : sufG[i + 1]);
		sufB[i] += (s[i] == 'B') + (i == n -1 ? 0 : sufB[i + 1]);
		// cout << sufR[i] << " " << sufG[i] << " " << sufB[i] << "\n";
	}

	ll ans = 0LL;
	for (int i = 0; i < n - 2; ++i) {
		char c = s[i];
		for (int j = i + 1; j < n - 1; ++j) {
			if (s[j] != c) {
				if ('R' != c && 'R' != s[j]) {
					ans += sufR[j + 1];
					if (2*j - i < n && s[j + j - i] == 'R')	--ans;
				}
				else if ('G' != c && 'G' != s[j]) {
					ans += sufG[j + 1];
					if (2*j - i < n && s[j + j - i] == 'G')	--ans;
				}
				else if ('B' != c && 'B' != s[j]) {
					ans += sufB[j + 1];
					if (2*j - i < n && s[j + j - i] == 'B')	--ans;
				}
			}
		}
	}


	cout << ans;
}
int main () {
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int tt = 1;
    // cin >> tt;
    for (int tc = 1; tc <= tt; ++tc) {
        solve();
    }
}                                  