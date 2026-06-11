#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;
using pl = pair<ll,ll>;

signed main(){
	ll n,k; cin>>n>>k;
	ll ans=0;
	rep(i,k,n+2){
		ll a=i*(i-1)/2;
		ll b=(2*n-i+1)*i/2;
		//cout<<a<<" "<<b<<endl;
		ans+=b-a+1;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}