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

ll bp (ll n, int k) {
	ll res = 1;
	while (k) {
		if (k % 2 == 1)
			res *= n;
		k /= 2;
		n *= n;
	}
	return res;
}

ll solve () {
	ll n; cin >> n;
	if (n % 2 == 1) return 0;

	ll res = 0;
	ll k = 1;
	while (true) {
		res += n / (bp (5, k) * 2);	

		if (bp (5, k + 1) > n) break;
		k ++;
	}

	return res;
}

main () { fast_in;
    int t = 1; //cin >> t;
    while (t --) {
    	cout << solve () << endl;    
    }
	return 0;
}