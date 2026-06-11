#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

ll mod = 1e9 + 7ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const int MAX_V = 500009;

typedef pair<int, ll> P;
vector<P> d(MAX_V);  // 結果格納　intは親　到達不可能なら-1, inf
vector< vector <P> > graph(MAX_V);

void dijkstra(int s) {
    priority_queue< P, vector<P>, greater<P> > que;
    for(int i = 0; i < d.size(); ++i) {
        d.at(i) = P(-1, INF);
    }
    que.push(make_pair(s, 0ll));
    d.at(s) = P(s, 0);
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.first;
        if(p.second > d.at(v).second) continue;
        for(int i = 0; i < graph.at(v).size(); ++i) {
            P edge = graph.at(v).at(i);
            if(d.at(edge.first).second > d.at(v).second + edge.second) {
                d.at(edge.first).second = d.at(v).second + edge.second;
                d.at(edge.first).first = v;
                que.push(make_pair(edge.first, d.at(edge.first).second));
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    rp(i, 0, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        graph.at(u).push_back(P(v+n, 1ll));
        graph.at(u+n).push_back(P(v+2*n, 1ll));
        graph.at(u+2*n).push_back(P(v, 1ll));
    }
    int s, t;
    scanf("%d%d", &s, &t);
    dijkstra(s);
    if(d.at(t).first == -1) printf("-1\n");
    else printf("%d\n", int(d.at(t).second) / 3);
    return 0;

}






