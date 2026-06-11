#include<bits/stdc++.h>
using namespace std;


#define rep(i, n) for(int i = 0; i < (n); i++)
using ULL = unsigned long long;


void solve() {
	int n; cin >> n;
	ULL bil7 = 1000000007;
	ULL ans = 1;
	string s; cin >> s;
	if (s[0] == 'W') { cout << 0 << endl; return; }
	if (s.back() == 'W') { cout << 0 << endl; return; }

	int pos = 1; bool prepos = true;
	for (size_t i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			if (prepos) {
				ans = ans * pos % bil7;
				pos--;
			}
			else {
				pos++;
			}
			prepos = !prepos;
		}
		else {
			if (prepos) {
				pos++;
			}
			else {
				ans = ans * pos % bil7;
				pos--;
			}
		}
	}

	if (pos != 0) { cout << 0 << endl; return; }

	rep(i, n) { ans = ans * (i + 1) % bil7; }

	cout << ans << endl;
}

int main() {

	solve();

	return 0;
}