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
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	ll n; cin>>n;
	if(n<4){
		ll a;
		cin>>a;
		a*=2;
		rep(i,0,n-2){
			ll b; cin>>b;
			a+=b;
		}
		cout<<a<<endl;
		return 0;
	}
	vl v(n-1);
	ll ans=0;
	rep(i,0,n-1){
		ll a; cin>>a;
		v[i]=a;
		if(i==0){
			ans+=v[i];
		}
		else{
			ans+=min(v[i-1],v[i]);
		}
	}
	ans+=v[n-2];
	cout<<ans<<endl;
		
	
	return 0;
}