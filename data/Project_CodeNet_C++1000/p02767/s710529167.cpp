#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	sort(all(a));
	ll res = 1e18;
			
	forn(i, 101) {
		ll s = 0;
		forn(j, n) {
			s += (a[j]-i)*(a[j]-i);
		}
		res = min(res, s);
	}
	cout << res << endl;
	return 0;
}

