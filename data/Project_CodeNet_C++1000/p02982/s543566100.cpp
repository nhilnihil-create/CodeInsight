#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair
#define mt make_tuple

bool check(int x) {
	int s = round(sqrt(x));
	return x == s * s;
}

const int N = 1100;
int n;
int d;
vector<int> v[N];


signed main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		v[i].resize(d);
		for (int &j : v[i]) {
			cin >> j;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int s = 0;
			for (int ind = 0; ind < d; ++ind) {
				int t = v[i][ind] - v[j][ind];
				s += t * t;
			}
			ans += check(s);
		}
	}

	cout << ans << "\n";
	return 0;
}
