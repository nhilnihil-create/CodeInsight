#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

struct edge{
    int to, cost;
    edge(int to, int cost):to(to), cost(cost){}
};

const int INF = 1e9;
int v, e, r;
int d[100010];
vector<edge> G[100010];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > q;
    fill(d, d + v, INF);
    q.push(P(0, s));
    d[s] = 0;
    while(q.size()){
        P p = q.top(); q.pop();
        int now = p.se;
        int nowCost = p.fi;
        if(nowCost > d[now]) continue;
        for(auto i: G[now]){
            int next = i.to;
            int cost = i.cost;
            if(d[next] > nowCost + cost){
                d[next] = nowCost + cost;
                q.push(P(d[next], next));
            }
        }
    }
}

signed main(){
    cin >> v >> e >> r;
    rep(i, 0, e){
        int s, t, d;
        cin >> s >> t >> d;
        G[s]. push_back(edge(t, d));
        // G[t]. push_back(edge(s, d));
    }
    dijkstra(r);
    rep(i, 0, v){
        if(d[i] == INF) o("INF");
        else o(d[i]);
    }
}