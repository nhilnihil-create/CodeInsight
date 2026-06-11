#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int dist[100005][3];

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int> > to(n);
    rep(i,m)
    {
        int u,v;
        cin >> u >> v;
        u--; v--;
        to[u].push_back(v);
    }
    int s,t;
    cin >> s >> t;
    s--; t--;

    rep(i,100005)
    {
        rep(j,3)
        {
            dist[i][j] = INF;
        }
    }
    queue<P> q;
    q.push(P(s,0));
    dist[s][0] = 0;
    while(!q.empty())
    {
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for (auto u : to[v])
        {
            int nl = (l+1)%3;
            if (dist[u][nl] != INF)continue;
            dist[u][nl] = dist[v][l] + 1;
            q.push(P(u,nl));
        }
    }
    int ans = dist[t][0];
    if (ans == INF)
    {
        ans = -1;
    }else
    {
        ans /=3;
    }
    cout << ans << endl;
    
    
}