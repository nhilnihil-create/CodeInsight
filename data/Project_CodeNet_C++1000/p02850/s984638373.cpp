#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {return (!b ? a : gcd(b, a % b));}


const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

vector<vector<pii>>adj;
vector<int>ans;

void dfs(int v,int prev,int skip){
     int color = 1;
     for(int j = 0;j<adj[v].size();j++){
        int nex = adj[v][j].first;
        if(nex == prev) continue;
        if(color == skip) color++;
        ans[adj[v][j].second] = color;
        dfs(adj[v][j].first,v,color);
        color++;
     }
}

void solve(){
     int n;cin >> n;
     adj.resize(n+1);
     ans.resize(n+1);
     int maxi = 0;
     for(int i = 0;i<n-1;i++){
        int v,u;cin >> v >> u;
        adj[v].push_back({u,i});
        adj[u].push_back({v,i});
        int j = adj[v].size();int k = adj[u].size();
        maxi = max(max(j,k),maxi);
     }
     dfs(1,-1,-1);
     cout << maxi <<endl;
     for(int i = 0;i<n-1;i++) cout << ans[i]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}