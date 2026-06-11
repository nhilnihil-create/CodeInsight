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

signed main(){
	string s; cin>>s;
	string t=s;
	ll n=s.size();
	vl a(n+1),b(n+1);
	ll cnt=0;
	rep(i,0,n){
		if(s[i]=='<')cnt++;
		else cnt=0;
		a[i+1]=cnt;
	}
	cnt=0;
	for(int i=n-1;i>=0;--i){
		if(s[i]=='>')cnt++;
		else cnt=0;
		b[i]=cnt;
	}
	ll ans=0;
	rep(i,0,n+1)ans+=max(a[i],b[i]);
	cout<<ans<<endl;
	return 0;
}