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
	ll n,a,b; cin>>n>>a>>b;
	--a; --b;
	vvl g(n,vl(0));
	rep(i,0,n-1){
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	g[a].push_back(b);
	g[b].push_back(a);
	vl ans(n+3);
	rep(i,0,n){
		queue<pair<ll,ll>> q;
		q.push(make_pair(i,0));
		vector<bool> seen(n);
		seen[i]=true;
		while(!q.empty()){
			pair<ll,ll> p=q.front(); q.pop();
			ll j,cost;
			tie(j,cost)=p;
			ans[cost]++;
			for(ll c:g[j]){
				if(seen[c])continue;
				seen[c]=true;
				q.push(make_pair(c,cost+1));
			}
		}
	}
	rep(i,1,n)cout<<ans[i]/2<<endl;
	return 0;
}