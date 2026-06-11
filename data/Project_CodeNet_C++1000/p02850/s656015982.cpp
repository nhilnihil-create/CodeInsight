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

vector<vector<pii>>adj(2);
vector<int>ans;
int maxi = 0;

void dfs(int v,int prev,int skip){
     int color = 1;
     for(int i = 0;i<adj[v].size();i++){
        if(adj[v][i].first==prev) continue;
        if(color == skip) color++;
        int idx = adj[v][i].second;
        ans[idx] = color;
        maxi = max(maxi,color);
        color++;
        dfs(adj[v][i].first,v,color-1);
}
}

void solve(){
     int n;cin >> n;
     adj.resize(n+1);
     ans.resize(n+1);
     for(int i = 0;i<n-1;i++){
        int v,u;cin >> v >> u;
        adj[v].push_back({u,i});
        adj[u].push_back({v,i});
     }
     dfs(1,0,0);
     cout << maxi <<endl;
     for(int i = 0;i<n-1;i++)
        cout << ans[i] <<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}