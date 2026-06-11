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
 
int a[maxn], b[maxn];

void solve () {
	string s; cin >> s; s += 'R'; s = '$' + s;
	int n = sz (s);
	int cntL, cntR, c;
	cntL = cntR = 0;
	vector <pii> v;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'R' && s[i-1] == 'L') {
			if ((cntL + cntR) % 2 == 0) {
				v.pb (mp (c-1, (cntL + cntR) / 2));				
				v.pb (mp (c, (cntL + cntR) / 2));				
			} else {
				if (cntR > cntL && cntR % 2 == 1) {
					v.pb (mp (c-1, (cntL + cntR) / 2 + 1));
					v.pb (mp (c, (cntL + cntR) / 2));
				} else if (cntR > cntL && cntR % 2 == 0) {
					v.pb (mp (c-1, (cntL + cntR) / 2));
					v.pb (mp (c, (cntL + cntR) / 2 + 1));				
				}	

				if (cntR < cntL && cntL % 2 == 0) {
					v.pb (mp (c-1, (cntL + cntR) / 2 + 1));
					v.pb (mp (c, (cntL + cntR) / 2));
				} else if (cntR < cntL && cntL % 2 == 1) {
					v.pb (mp (c-1, (cntL + cntR) / 2));
					v.pb (mp (c, (cntL + cntR) / 2 + 1));				
				}	
			}
			cntL = 0, cntR = 1;
		} else if (s[i] == 'R') {
			cntR ++;
		} else if (s[i] == 'L' && s[i - 1] == 'R') {
			c = i;
			cntL ++;
		} else if (s[i] == 'L') {
			cntL ++;
		}

		//cout << cntL << ' ' << cntR << endl;
	}

	for (auto to: v) {
		a[to.first] = to.second;
	}

	for (int i = 1; i < n-1; i ++)
		cout << a[i] << ' ';
}

main () { fast_in;
    int t = 1; //cin >> t;
    while (t --) {
    	solve ();    
    }
	return 0;
}