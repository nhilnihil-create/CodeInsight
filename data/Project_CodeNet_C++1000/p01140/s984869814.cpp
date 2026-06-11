#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>
#include <bitset>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = (1LL << 31) - 1;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,N) for(int i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1
#define MAX_N 100100 * 3

int n[2];
ll cnt[2][1500010];
ll h[2][1500010];

int main() {
	while (cin >> n[0] >> n[1]) {
		if (n[0] + n[1] == 0) {
			return 0;
		}
		REP(i, 2) {
			fill(cnt[i], cnt[i] + 1500010, 0);
			fill(h[i], h[i] + 1500010, 0);
		}
		REP(i, 2) {
			FOR(j, 1, n[i] + 1)cin >> h[i][j];
			REP(j, n[i])h[i][j + 1] += h[i][j];
		}
		REP(i, 2) {
			REP(j, n[i]) {
				FOR(k, j + 1, n[i] + 1) {
					cnt[i][h[i][k] - h[i][j]]++;
				}
			}
		}
		ll ans = 0;
		REP(i, 1500010) {
			ans += (cnt[0][i] * cnt[1][i]);
		}
		cout << ans << endl;
	}
}