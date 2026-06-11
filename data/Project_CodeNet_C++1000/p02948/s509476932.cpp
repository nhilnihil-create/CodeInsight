//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < n;i++)
#define INF 1e+9

struct edge {
    int to;
    double cost;
};

// <最短距離, 頂点の番号>
using P = pair<double, int>;

int V;
const int ci = 2e5+ 5;
vector<edge> G[ci];
double d[ci];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) { //cout << "On" << endl;
        P p = que.top();
        que.pop();
        int v = p.second; //cout << "v=" << v << endl;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i]; //cout << "koo" << endl;
            if (d[e.to] > d[v] + e.cost) { //cout << e.cost << endl;
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


int main(){
    int n, m; cin >> n >> m;
    priority_queue<int> pq;
    vector<int> v[100005];
    rep(i,n){
        int a, b; cin >> a >> b;
        v[a].pb(b);
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++){
        for(auto j : v[i]) pq.push(j);
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}
