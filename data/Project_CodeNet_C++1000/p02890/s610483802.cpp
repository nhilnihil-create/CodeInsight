#include <bits/stdc++.h>                                           
 
#define int long long
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
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
 
 
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, block = 555;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, N = 3e5 + 48, mod = 1e9 + 7;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;


int n, x, cnt[N], cnt1[N], pr[N], suff[N];
pii f[N];

main () {
	cin >> n;
	forn (i, 1, n) {
		cin >> x;
		++cnt[x];
	}

	forn (i, 1, n)
		++cnt1[cnt[i]];

	forn (i, 1, n) 
		pr[i] = pr[i - 1] + cnt1[i] * i;

	forev (i, n, 1)
		suff[i] = suff[i + 1] + cnt1[i];

	forn (i, 1, n) {
		f[i].f = pr[i - 1] / i + suff[i];					 
		f[i].s = i;
	}
	
	sort(f + 1, f + 1 + n);
	reverse(f + 1, f + 1 + n);
	int j = 1, mx = 0;
	vi ans;
	forev (k, n, 1) {
		while (j <= n && f[j].f >= k) 
			mx = max(mx, f[j++].s);
		ans.pb(mx);
	}
	reverse(all(ans));					
	for (auto x : ans)
		cout << x << endl;
}
