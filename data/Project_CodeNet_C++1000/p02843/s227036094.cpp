#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll LINF = 1e18;
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
#define next asdnext
#define prev asdprev
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define dump(x)  cout << #x << " = " << (x) << endl;	// debug
#define SZ(x) ((ll)(x).size())
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (ll i = (a); i >= (b); i--)
#define ps(s) cout << #s << endl;
#define pv(v) cout << (v) << endl;
#define pvd(v) cout << setprecision(16) << (v) << endl;
#define ALL(a)  (a).begin(),(a).end()
#define RANGE(a, left, right)  (a).begin()+(left),(a).begin()+(right)	// left to (right-1)


int main() {
	int x;
	cin >> x;
	int kosu = x / 100;
	int hasu = x % 100;
	FOR(i, 0, 100) {
		FOR(j, 0, 50) {
			FOR(k, 0, 34) {
				FOR(m, 0, 25) {
					FOR(n, 0, 20) {
						if (i * 1 + j * 2 + k * 3 + m * 4 + n * 5 == hasu) {
							if (i + j + k + m + n <= kosu) {
								ps(1);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	ps(0)
	return 0;
}