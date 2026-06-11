#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
typedef pair<int, int> P;

int dist[100005][3];

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
    }

    int sv, tv;
    cin >> sv >> tv;
    --sv; --tv;

    queue<P> q;
    q.push(P(sv,0));
    rep(i,n)rep(j,3) dist[i][j] = inf;
    dist[sv][0] = 0;
    while(q.size()!=0) {
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for(int u: to[v]) {
            int nl = (l+1)%3;
            if(dist[u][nl] != inf) continue;
            dist[u][nl] = dist[v][l]+1;
            q.push(P(u, nl));
        }    
    }
    int ans = dist[tv][0];
    if(ans==inf)ans = -1;
    else ans /= 3;
    cout << ans << endl;

    return 0;
}