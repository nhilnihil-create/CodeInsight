#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define min_3(a,b,c) min(a,min(b,c))
#define max_3(a,b,c) max(a,max(b,c))
#define nout(ans) cout << (ans) << "\n"
#define sout(ans) cout << (ans) << " "
using namespace std;

const double pi = 3.14159265359;
const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const ll N = 2e3+5; 
/*
Decimal Places: cout << fixed << setprecision(n) << ans << endl
*/

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

ll raise(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


int n, x, y; vector <int> adj[N];
int dis[N]; bool vis[N];
int ans[N]; 

void solve()
{
    cin >> n >> x >> y;
    for (int i=1; i<n; ++i) {
    	adj[i].pb(i+1); 
    	adj[i+1].pb(i);
    }
    adj[x].pb(y);
    adj[y].pb(x);
    fill(ans,ans+n+2,0);
    for (int i=1; i<n; ++i) {
    	fill(dis,dis+n+2,0); fill(vis,vis+n+2,false);
    	queue <int> q; vis[i]=true; dis[i]=0; q.push(i);
    	while (!q.empty()) {
    		int s=q.front(); q.pop();
    		for (auto u : adj[s]) {
    			if (vis[u]) continue;
    			vis[u]=true;
    			dis[u]=dis[s]+1;
    			q.push(u);
    		}
    	}
    	for (int j=1; j<=n; ++j) {
    		//sout(dis[j]);
    		if (j>i) ans[dis[j]]++;
    	}//cout << endl;
    }
    for (int i=1; i<n; ++i) nout(ans[i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++)
    {
        solve();
    }
    return 0;
}