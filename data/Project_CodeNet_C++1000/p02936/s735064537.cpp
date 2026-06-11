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
bool cmp(pair<ll,ll>a,pair<ll,ll>b){return a.first>b.first;}

const ll mod = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;
const ld pi = 3.141592653589793;

vector< vector<int> >adj;
vector<int>ans;

void dfs(int v,int prev,int val){
     for(int i = 0;i<adj[v].size();i++){
        if(adj[v][i]==prev) continue;
        ans[adj[v][i]] += val;
        dfs(adj[v][i],v,ans[adj[v][i]]);
     }
}

void solve(){
     int n,m;cin >> n >> m;
     adj.resize(n+1);ans.resize(n+1);
     for(int i = 0;i<n-1;i++){
        int v,u;cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
     }
     for(int i = 0;i<m;i++){
        int j,k;cin >> j >> k;
        ans[j] += k;
     }
     dfs(1,0,ans[1]);
     for(int i = 1;i<=n;i++) cout << ans[i] <<' ';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    solve();
    return 0;
}
