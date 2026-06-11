#include "bits/stdc++.h"
using namespace std;
#define int long long
#define REP(i, s, n) for (signed i = (s); i < signed(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(c) (c).begin(), (c).end()


const int INF = 1 << 29;


using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, -1, 0, 1 };
const int MOD = 1000000007;

signed main() {
	auto tax = [](int p, int x) { return p * (100 + x) / 100; };
	int x, y, s; 
	while (cin >> x >> y >> s && x) {
		int ans = 0;
		REP(i, 1, s) REP(j, i, s) {
			if (tax(i, x) + tax(j, x) != s) continue;
			ans = max(ans, tax(i, y) + tax(j, y));
		}
		cout << ans << endl;
	}
}