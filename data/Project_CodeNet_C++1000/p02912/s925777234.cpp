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

signed main(){
	ll n,m; cin>>n>>m;
	priority_queue<ll> q;
	rep(i,0,n){
		ll a; cin>>a;
		q.push(a);
	}
	while(m--){
		ll k=q.top(); q.pop();
		k/=2; q.push(k);
	}
	ll ans=0;
	rep(i,0,n){
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<endl;
	
	return 0;
}