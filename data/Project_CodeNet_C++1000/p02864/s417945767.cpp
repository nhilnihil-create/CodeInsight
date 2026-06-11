#include <bits/stdc++.h>                                           
 
#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
using namespace std;
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;
typedef unsigned long long ull;         
typedef vector < pii > vpii;
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;                             
 
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, maxn = 4e5 + 148, mod = 1e9 + 7, N = 3e2 + 11;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;


int n, k, dp[N][N], a[N];


main () {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}
	forn (i, 1, n)
		cin >> a[i];

	forn (i, 0, n)
		forn (j, 0, n)
			dp[i][j] = INF;

	dp[0][0] = 0;
	forn (i, 1, n) 
		forn (j, 1, i) 
			forn (z, 0, i - 1) 
				dp[i][j] = min(dp[i][j], dp[z][j - 1] + max(0ll, a[i] - a[z])); 
	

	int ans = INF;
	forn (i, 1, n)	 
		ans = min(ans, dp[i][n - k]); 
		
	cout << ans << endl;
}
