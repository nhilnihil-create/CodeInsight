#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int res = 0;
	for (char i = '0'; i <= '9'; i++) {
		for (char j = '0'; j <= '9'; j++) {
			for (char k = '0'; k <= '9'; k++) {
				int check = 0;
				for (int idx = 0; idx < n; idx++) {
					if (check == 0 && s[idx] == i) {
						check++;
					}
					else if (check == 1 && s[idx] == j) {
						check++;
					}
					else if (check == 2 && s[idx] == k) {
						check++;
					}
				}
				if (check == 3) res++;
			}
		}
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}