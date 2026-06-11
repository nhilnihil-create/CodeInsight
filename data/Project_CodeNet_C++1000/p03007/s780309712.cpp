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

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

int v[MAXN];

void solve(){
	int n;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", &v[i]);
	}
	sort(v, v + n);
	int ans = v[n - 1] - v[0];
	REP(i, 1, n - 1) {
		ans += abs(v[i]);
	}
	printf("%d\n", ans);
	for(int i = n - 2; i > 0 && v[i] >= 0; i--) {
		printf("%d %d\n", v[0], v[i]);
		v[0] -= v[i];
	}
	for(int i = 1; i < n - 1 && v[i] < 0; i++) {
		printf("%d %d\n", v[n - 1], v[i]);
		v[n - 1] -= v[i];
	}
	printf("%d %d\n", v[n - 1], v[0]);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
