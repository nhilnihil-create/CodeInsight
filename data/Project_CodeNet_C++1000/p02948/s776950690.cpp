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
ll modpow(ll a,ll b,ll p){
	if(b==0) return 1;
	if(b%2==0){
		ll t=modpow(a,b/2,p);
		return t*t%p;
	}
	return a*(modpow(a,b-1,p))%p;
} 
//cout << fixed << setprecision(桁数);
//__builtin_popcount()
signed main(){
	ll n,m; cin>>n>>m;
	vector<pl> vec(n);
	priority_queue<ll> q;
	rep(i,0,n)cin>>vec[i].first>>vec[i].second;
	sort(all(vec));
	vec.push_back(make_pair(MOD,MOD));
	ll j=0;
	ll ans=0;
	rep(i,1,m+1){
		while(j<n && vec[j].first<=i){
			q.push(vec[j].second);
			j++;
		}
		if(q.empty())continue;
		ll add=q.top(); q.pop();
		ans+=add;
	}
	cout<<ans<<endl;




	return 0;
}
