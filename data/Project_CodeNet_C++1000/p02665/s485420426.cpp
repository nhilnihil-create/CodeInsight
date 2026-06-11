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
using vvb=vector<vector<bool>>;
using vb= vector<bool>;
ll f(ll a,ll b,ll p){
	if(b==0) return 1;
	if(b%2==0){
		ll t=f(a,b/2,p);
		return t*t%p;
	}
	return a*(f(a,b-1,p))%p;
} 

//__builtin_popcount()
signed main(){
	ll n; cin>>n;
	vl a(n+1); rep(i,0,n+1)cin>>a[i];
	if(n==0 && a[0]==1){
		cout<<1<<endl;
		return 0;
	}
	if(a[0]!=0){
		cout<<-1<<endl;
		return 0;
	}
	vl b(n+1);
	for(ll i=n;i>=0;--i){
		b[i]=a[i];
		if(i!=n)b[i]+=b[i+1];
	}
	vl ans(n+1);
	ans[0]=1;
	rep(i,1,n+1){
		ans[i]=min({(ans[i-1]-a[i-1])*2,b[i]});
		if(a[i]>ans[i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	ll k=0; rep(i,0,n+1)k+=ans[i];
	cout<<k<<endl;


	return 0;
}