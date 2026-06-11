/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back   
#define sz(a) ((int)a.size())
using namespace std;
typedef long long ll ;
const int mod = 1e9 + 7;
const int N = 1e5 + 1;
const ll inf = 1e18 ;
ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}

int n , k;
vector<int> g[N];

ll dfs(int u , int p = -1){
    int use = k - 1 - (p != -1);
    ll ans = (p == -1 ? k : 1); 
    for(int& v : g[u]){
        if(v == p) continue ;
        ans = (1LL * ans * (use--)) % mod;
        ans = (1LL * ans * dfs(v , u)) % mod ;
    }
    return ans ;
}


void solve(){
    cin >> n >> k ;
    for(int i = 0 ; i < n - 1; ++i){
        int x , y;
        cin >> x >> y;
        --x , --y ;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout << dfs(0) % mod ;
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC = 1, t = 0;
    // cin >> TC ;
    while(t++ < TC)
    {
        // cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}