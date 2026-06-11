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
#define MOD 998244353 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	string s; cin>>s;
	ll n=s.size();
	map<ll,ll> mp;
	mp[0]++;
	reverse(all(s));
	ll cnt=1;
	ll now=0;
	for(ll i=0;i<n;i++){
		ll j=cnt*(s[i]-'0')%2019;
		cnt*=10; cnt%=2019;
		now+=j;
		now%=2019;
		mp[now]++;
	}
	ll ans=0;
	for(auto c:mp){
		//if(c.second>1)cout<<c.first<<" ";
		ll j=c.second*(c.second-1)/2;
		ans+=j;
	}
	cout<<ans<<endl;
	return 0;
}