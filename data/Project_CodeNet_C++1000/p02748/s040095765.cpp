#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	ll a,b,m; cin>>a>>b>>m;
	vector<ll> A(a);
	vector<ll> B(b);
	ll amin=LINF;
	ll bmin=LINF;
	rep(i,0,a){
		cin>>A[i];
		chmin(amin,A[i]);
	}
	rep(i,0,b) {
		cin>>B[i];
		chmin(bmin,B[i]);
	}
	ll ans=amin+bmin;
	rep(i,0,m){
		ll o,p,q;
		cin>>o>>p>>q;
		chmin(ans,A[o-1]+B[p-1]-q);
	}
	cout<<ans<<endl;
}