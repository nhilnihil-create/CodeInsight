#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int l, r;
	cin >> l >> r;
	if (r - l > 2019)r = l + 2019;
	int ans = 2020;
	for (int i = l; i < r; i++) {
		for (int j = i + 1; j <= r; j++) {
			ans = min(ans, ((i % 2019) * (j % 2019)) % 2019);
		}
	}
	cout << ans << endl;
	return 0;
}

