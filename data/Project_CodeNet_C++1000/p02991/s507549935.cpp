#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e12;

struct edge{
    int to, cost;
};

int V,E;
vector<vector<edge>> graph;
vector<long long int> d;

void Dijkstra(int s){// s = starting point
    priority_queue<
        pair<int, int>// temporarily keeping (shortest distance, vertex)
        , vector<pair<int, int>>, greater<pair<int, int>>// shorter ones first
    > pq;

    // initialize (INF)
    for(int i=0; i<V; i++){
        d[i] = INF;
    }
    d[s] = 0;
    pq.push({0,s});

    // search
    pair<int, int> current;// (shortest-distance confirmed, vertex)
    while(!pq.empty()){
        current = pq.top(); pq.pop();

        int v = current.second;
        if(d[v] < current.first){
            continue;// ignore (not the shortest path)
        }
        // else (need to check)
        for(edge e : graph[v]){// adjacent nodes
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;// update minimum cost
                pq.push({d[e.to], e.to});
            }
        }
    }
}


int main(){
    cin >> V >> E;
    V *= 3;
    graph.resize(V);
    d.resize(V);

    for(int i=0; i<E; i++){
        int u, v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        graph[3*u].push_back({3*v+1, 1});
        graph[3*u+1].push_back({3*v+2, 1});
        graph[3*u+2].push_back({3*v, 1});
    }

    int s, t;
    cin >> s >> t;
    s -= 1;
    t -= 1;

    Dijkstra(3*s);
    if(d[3*t] == INF) cout << -1         << endl;
    if(d[3*t] != INF) cout << d[3*t] / 3 << endl;
    return 0;
}