
#include <bits/stdc++.h>
#define bp(x) __builtin_popcountll(x)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll int64_t
#define fw(i, l, r, c) for(ll i = l; i <= r; i += c)
#define bw(i, r, l, c) for(ll i = r; i >= l; i -= c)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
const ll mod = 1e9 + 7, inf = 1061109567, N = 2e3 + 5;
const long long infll = 4557430888798830399;

int n, a[N], d[N];

signed main(){
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	fastio;
	cin >> n;
	fw(i, 0, n - 1, 1){
		cin >> a[i];
	}
	sort(a, a + n);
	if(n == 3){
		if(a[0] + a[1] <= a[2]){
			return cout << 0, 0;
		}
		return cout << 1, 0;
	}else if(n <= 2){
		return cout << 0, 0;
	}
	d[0] = 0;
	d[1] = a[2] - a[1];
	fw(i, 2, n - 2, 1){
		d[i] = d[i - 1] + a[i + 1] - a[i];  
	}
	int res = 0;
	fw(i, 0, n - 3, 1){
		fw(j, i + 1, n - 2, 1){
			fw(k, 0, i, 1){
				if(a[k] > d[j] - d[i]){
					res++;
				}
			}
		}
	}
	cout << res;
}