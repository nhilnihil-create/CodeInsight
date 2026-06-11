#include "bits/stdc++.h"
#define int long long
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
const int MOD = 1000000007;
const long double EPS = 1e-8;
using vi = vector <int>;
using vvi = vector <vi>;

signed main() {
	int n, p;
	while (cin >> n >> p, n) {
		int wan = p;
		int step = 0;
		int have[n] = {};
		int ans;
		while (1) {
			rep (i, n) {
				if (wan != 0) {
					wan--;
					have[i]++;
					if (!wan) {
						bool flag = true;
						rep (j, n) {
							if (j == i) continue;
							if (have[j]) {
								flag = false;
							}
						}
						if (flag) {
							cout << i << endl;
							goto end;
						}
					}
				} else {
					wan += have[i];
					have[i] = 0;
				}
			}
			step++;
		}
	end:;
	}
	return 0;
}
