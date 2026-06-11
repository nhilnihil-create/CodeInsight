#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	ll n,l; cin>>n>>l;
	ll total=0;
	vl vec(n);
	rep(i,1,n+1){
		total+=l+i-1;
		vec[i-1]=l+i-1;
	}
	ll ans=MOD;
	rep(i,0,n){
		ll a=total-vec[i];
		ll b=abs(total-a);
		chmin(ans,b);
	}
	if(total<0) cout<<total+ans;
	else cout<<total-ans;
	return 0;
}