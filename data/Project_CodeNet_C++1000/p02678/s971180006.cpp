//   PIGMEISTER™   //

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define sidha(i,x,n) for(ll i=(ll)(x);i<(ll)(n);++i)
#define ulta(i,x,n) for(ll i=(ll)(x);i>=(ll)(n);--i)
#define sab(a) a.begin(),a.end()
#define bas(a) a.rbegin(),a.rend()
#define test ll _;cin>>_;while(_--)
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD (ll)1000000007
//#define MOD (ll)998244353
#define PI (ld)3.141592653589793238
#define MAX 100005

ll ans[MAX];

ll bfs(vector<ll> adj[], ll n, ll root = 1) {
    queue<ll> q;
    bool vis[n+5] = {0};
    ll count = 1;
    q.push(root);
    vis[root] = 1;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push(v);
                vis[v] = 1;
                ans[v] = u;
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    jaldi;
    
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n+1];
    ll a, b;
    sidha (i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll f = bfs(adj, n);
    if (f < n) return cout << "No", 0;
    cout << "Yes\n";
    sidha (i, 2, n+1) cout << ans[i] << '\n';
    
    return 0;
}
