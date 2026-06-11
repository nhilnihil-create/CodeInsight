#include <bits/stdc++.h>
#define endl '\n'
#define fast_in ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp  make_pair
#define pb  push_back
#define  sz(x)   (int)x.size()
#define  all(x)  x.begin(), x.end()
#define	 allr(x)  x.rbegin(), x.rend()
#define  bit(x)  __builtin_popcountll(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
const int inf = (int) 1e9+99999, mod = (int)1e9+7;
const ll linf = (ll) 2e18+99999;
int mul (int x, int y) { return ((ll)x * y) % mod; } 
int sub (int x, int y) { x -= y; if (x < 0) return x + mod; return x; } 
int add (int x, int y) { x += y; if (x >= mod) return x - mod; return x; }
 
const int maxn = (int) 3e5;


#define int ll

int cost[maxn], k[maxn], c[1001][50];
int d[5001][2];

void solve () {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> cost[i] >> k[i];
		for (int j = 1; j <= k[i]; j ++) {
			cin >> c[i][j];	
			c[i][j] --;
		}
	}


	for (int mask = 0; mask < (1 << n); mask ++)
		for (int j = 0; j <= n; j ++)
		d[mask][j] = d[mask][j] = linf; 
	d[0][0] = 0;

	for (int i = 1; i <= m; i ++) {
		for (int mask = 0; mask < (1 << n); mask ++)
			d[mask][i] = d[mask][i-1];
		
		for (int mask = 0; mask < (1 << n); mask ++) {
			int mask2 = mask; for (int j = 1; j <= k[i]; j ++) mask2 |= (1 << c[i][j]);
			d[mask2][i] = min (d[mask2][i], d[mask][i-1] + cost[i]);		
		}
	}


	int res = d[(1 << n)-1][m];

	if (res == linf) res = -1;
	cout << res;
}

main () { fast_in;
    int t = 1; //cin >> t;
    while (t --) {
    	solve ();    
    }
	return 0;
}