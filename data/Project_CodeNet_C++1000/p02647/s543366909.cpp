#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	rep(ki, k){
		vector<ll> b(n+1);
		rep(i,n){
			ll l = max(ll(0), i-a[i]);
			ll r = min(n, i+a[i]+1);
			b[l]++;
			b[r]--;
		}
		rep(i,n) b[i+1]+=b[i];
		b.pop_back();
		if(a == b) break;
		a = b;
	}
	rep(i,n-1) cout << a[i] << " ";
	cout << a[n-1] << endl;
 	return 0;
}