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
const ll MOD = 1000000007;

struct edge {
    int to;
    ll cost;
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

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

vector<edge> g[100005];
int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> r,l,check,R,L;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            cnt++;
        }else{
            if(cnt) {
                r.pb(cnt);
                check.pb(i);
            }
            cnt = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 'L'){
            cnt++;
        }else{
            if(cnt) l.pb(cnt);
            cnt = 0;
        }
    }l.pb(cnt);

    int N = r.size();
    vector<int> ans(n);
    for(int i = 0; i < N; i++){
        ans[check[i] - 1] = r[i] - r[i] / 2 + l[i] / 2;
        ans[check[i]] = l[i] - l[i] / 2 + r[i] / 2;
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
}
