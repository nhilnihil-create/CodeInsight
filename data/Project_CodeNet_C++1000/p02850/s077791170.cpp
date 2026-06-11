// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

struct Edge{
    int a, b, i, c;
};

int main(){
    int N;
    cin >> N;
    vector<vector<Edge>> G(N);
    vector<int> Edge_color(N - 1), P_color(N);

    rep(i, N - 1){
        Edge e;
        cin >> e.a >> e.b;
        e.a--;
        e.b--;
        e.i = i;
        G[e.a].push_back(e);
    }

    P_color[0] = -1;
    int K = 1;
    queue<int> que;
    que.push(0);

    while(!que.empty()){
        int a = que.front();
        que.pop();
        int p = P_color[a];
        int color = 0;
        for(Edge e : G[a]){
            color++;
            if(color == p) color++;
            e.c = color;
            Edge_color[e.i] = color;
            P_color[e.b] = color;
            que.push(e.b);
        }
        K = max(K, color );
    }

    cout << K << endl;

    rep(i, N - 1){
        cout << Edge_color[i] << endl;
    }
}