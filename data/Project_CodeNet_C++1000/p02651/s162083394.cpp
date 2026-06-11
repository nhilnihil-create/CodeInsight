#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

void solve() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	string s;
	cin >> s;

	vector<int> gauss(60, -1);

	for (int i = v.size() - 1; i >= 0; i--) {

		if (s[i] == '0') {
			int cur = v[i];
			for (int j = 59; j >= 0; j--) {
				if (!((1LL<<j)&cur)) continue;
				if (gauss[j] == -1) {
					gauss[j] = cur;
					break;
				}

				cur ^= gauss[j];
			}
		}

		else {
			int cur = v[i];
			for (int j = 59; j >= 0; j--) {
				if (!((1LL<<j)&cur)) continue;
				if (gauss[j] == -1) {
					cout << "1\n";
					return;
				}

				cur ^= gauss[j];
			}
		}
	}

	cout << "0\n";

}

main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}
