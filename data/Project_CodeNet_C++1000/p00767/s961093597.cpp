#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define each(i,c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1000000000;
const int mod = 1000000007;
const double eps = 1e-9;
const int dx[] = { -1, 0, 1, 0};
const int dy[] = { 0, -1, 0, 1};

int main() {
	// cin.tie(0); // tie
	// ios::sync_with_stdio(false); // sync
	int h, w;
	while (cin >> h >> w, h || w) {
		int d = h * h + w * w;
		int ans_h = 150, ans_w = 150;
		for (int i = 1; i <= 150; ++i) {
			for (int j = i + 1; j <= 150; ++j) {
				int tmp_d = i * i + j * j;
				int ans_d = ans_h * ans_h + ans_w * ans_w;
				if (d < tmp_d || (d == tmp_d && h < i)) {
					if (ans_d > tmp_d || (tmp_d == ans_d && i < ans_h)) {
						ans_h = i; ans_w = j;
					}
				}
			}
		}
		cout << ans_h << ' ' << ans_w << endl;
	}
	return 0;
}