#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int,int> P;
 
const int INF = 1001001001;
int dist[100005][3];


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > to(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
    }
    int s,t;
    cin >> s >> t;
    s--;t--;
    rep(i,n)rep(j,3) dist[i][j] = INF;
    queue<P> q;
    q.push(P(s,0));
    dist[s][0] = 0;
    while (!q.empty()) {
        int v = q.front().first;
        int parity = q.front().second;
        q.pop();
        for (int u : to[v]){
            int np = (parity+1)%3;
            if (dist[u][np] != INF) continue;
            dist[u][np] = dist[v][parity]+1;
            q.push(P(u,np));
        }
    }
    int ans = dist[t][0];
    if (ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
    return 0;
}