#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

using Graph = vector<vector<int>>;
ll k;
vector<ll> ans(100010);

void dfs(const Graph &G, ll v, ll p) { 
    ll now = k-2; if(v == 0)now++;
	for (auto nv : G[v]) {
		if (nv == p)continue;
		ans[nv] = now;
		dfs(G, nv, v);
        chmin(now, max(now-1, 0LL));
	}
}


int main() {
    ll n;
    cin >> n >> k;
    Graph G(n);
    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll num = 1;
    ans[0] = k;
    dfs(G, 0, -1);
    rep(i, n)num = num * ans[i] % mod;
    cout << num << endl;
}