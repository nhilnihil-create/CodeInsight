#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
const int INF = 2000000000;
using namespace std;


class Edge{
    public:
        int to, cost;
        Edge(int to, int cost) : to(to) ,cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
vector<int> dis;

bool bellmanFord(AdjList g, int n, int s) { // n???????????°???s???????§???????
    dis = vector<int>(n, INF);
    dis[s] = 0; // ????§????????????¢???0
    rep(i,n){
        rep(v,n){
            rep(k,g[v].size()){
                Edge e = g[v][k];
                if (dis[v] != INF && dis[e.to] > dis[v] + e.cost) {
                    dis[e.to] = dis[v] + e.cost;
                    if (i == n - 1) return true; // n??????????????´??°???????????????????????????????????¨
                }
            }
        }
    }
    return 0;
}

int main(){
    int v, e, r;
    cin >> v >> e >> r;
    AdjList g(v);
    rep(i,e){
        int a, b ,c;
        cin >> a >> b >> c;
        g[a].emplace_back(b,c);
    }
    if(bellmanFord(g, v, r) == 1) cout << "NEGATIVE CYCLE" << endl;
    else{
        for(auto it:dis){
            if(it == INF) cout << "INF" << endl;
            else cout << it << endl;
        }
    }
}