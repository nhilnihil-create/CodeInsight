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
	ll n; cin>>n;
	string s; cin>>s;
	ll a=0,b=0,c=0;
	rep(i,0,n){
		if(s[i]=='R')++a;
		else if(s[i]=='G')++b;
		else ++c;
	}
	ll ans=a*b*c;
	rep(i,0,n){
		ll cnt=1;
		while(true){
			ll j=i+cnt;
			ll k=j+cnt;
			if(k>=n)break;
			if(s[i]!=s[j] && s[j]!=s[k] && s[i]!=s[k])--ans;
			++cnt;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}