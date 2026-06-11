#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int v[2][MAXN];

int cnt[MAXN];

void solve(){
	int n, k;
	scanf("%d%d", &n, &k);
	REP(i, 0, n) {
		scanf("%d", &v[1][i]);
	}
	REP(j, 0, k) {
		int fl = 0;
		if (j > 10) {
			REP(i, 0, n) {
				if (v[0][i] != v[1][i]) {
					fl = 1;
					break;
				}
			}
			if (!fl) {
				break;
			}
		}
		REP(i, 0, n) {
			v[0][i] = v[1][i];
			v[1][i] = 0;
			cnt[i] = 0;
		}
		cnt[n] = 0;
		
		REP(i, 0, n) {
			int l = max(0, i - v[0][i]);
			int r = min(n - 1, i + v[0][i]);
			cnt[l]++;
			cnt[r + 1]--;
		}
		REP(i, 0, n) {
			if (i) {
				cnt[i] += cnt[i - 1];
			}
			v[1][i] = cnt[i];
		}
	}
	REP(i, 0, n) {
		printf("%d ", v[1][i]);
	}
	putchar('\n');
}

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
