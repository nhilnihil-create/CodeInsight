#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;



template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


// dijkstra法ライブラリここから-----------------------------------------------------------------------------//

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

// dijkstra法ライブラリここまで-----------------------------------------------------------------------------//


int main() {
    int N, M; cin >> N >> M;
    rp(i, 0, M) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        graph.at(u).emplace_back(v+N, 1ll);
        graph.at(u+N).emplace_back(v+2*N, 1ll);
        graph.at(u+2*N).emplace_back(v, 1ll);
    }

    int S, T; cin >> S >> T;
    S--; T--;
    dijkstra(S);
    if(d.at(T).first == -1) cout << -1 << endl;
    else cout << d.at(T).second / 3ll << endl;
    return 0;
}