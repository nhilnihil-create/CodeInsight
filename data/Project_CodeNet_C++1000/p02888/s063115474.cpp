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
	ll n,m; cin>>n;
	vl a(n);
	rep(i,0,n)cin>>a[i];
	sort(all(a));
	ll ans=0;
	rep(i,0,n){
		rep(j,i,n){
			if(i==j)continue;
			ll k=a[i]+a[j];
			//cout<<"i:"<<a[i]<<" j:"<<a[j];
			ll l=upper_bound(all(a),k-1)-a.begin();
			ll m=l-j-1;
			//cout<<"m:"<<l-j-1<<endl;
			if(m>=0)ans+=m;
		}
	}
	cout<<ans<<endl;
			
			
			
	
}