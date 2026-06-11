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
 
int a[maxn];

void solve () {
	int n, m;
	cin >> n >> m;
	multiset <int> s;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		s.insert (a[i]);
	}	

	for (int i = 1; i <= m; i ++) {
		int x = *--s.end ();
		s.erase (--s.end ());
		s.insert (x / 2);
	}

	ll res = 0;
	for (auto to: s)
		res += to;

	cout << res;
}

main () { fast_in;
    int t = 1; //cin >> t;
    while (t --) {
    	solve ();    
    }
	return 0;
}