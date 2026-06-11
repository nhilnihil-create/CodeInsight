#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000 //14
#define N 210000

vector<ll> a(N);
vector<ll> f(N);

ll query(ll x, ll n, ll k){
	ll z = 0; ll y = 0;
	REP(i,n) {
		z+=max(y,a[i]-x/f[i]);
		//cout << x << " " << i << " " << max(y,a[i]-x/f[i]) << endl;
	}
	if (z<=k) return true;
	return false;
}
int main(){
	ll n, k, mid; cin >> n >> k;
	REP(i,n) cin >> a[i];
	REP(i,n) cin >> f[i];
	sort(a.begin(),a.begin()+n);
	sort(f.begin(),f.begin()+n);
	reverse(f.begin(),f.begin()+n);
	//REP(i,n) cout << a[i] << " " << f[i] << endl;
	ll right = 0;
	REP(i,n) right = max(right,a[i]*f[i]);
	ll left = 0; right++;
	while(right-left>1){
		mid = (right+left)/2;
		if (query(mid,n,k)) right=mid;
		else left=mid;
	}
	if (right==1&&query(0,n,k)) cout << 0 << endl;
	else cout << right << endl;
}