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
	vl a(n+1),b(n);
	ll m=0;
	rep(i,0,n+1){
		cin>>a[i];
		m+=a[i];
	}
	
	rep(i,0,n)cin>>b[i];
	ll ans=0;
	rep(i,0,n){
		ll k=b[i];
		ans+=min(k,a[i]+a[i+1]);
		k-=a[i];
		if(0<k){
			a[i+1]=max((ll)0,a[i+1]-k);
		}
	}
	cout<<ans<<endl;
	return 0;
}
