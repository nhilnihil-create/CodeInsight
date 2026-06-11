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
ll dp[100005][13];

int main(){
    string s; cin >> s;
    int n = s.size();


    if(s[0] == '?') rep(i,10) dp[0][i] = 1;
    else {
        int c = s[0] - '0';
        dp[0][c] = 1;
    }

    for(int i = 0; i < n; ++i){
        if(s[i] == '?'){
            for(int k = 0; k < 13; k++){
                for(int j = 0; j < 10; j++){
                    dp[i][(k * 10 + j) % 13] += dp[i-1][k];
                    dp[i][(k * 10 + j) % 13] %= MOD;
                }
            }
        }else{
            int c = s[i] - '0';
            for(int k = 0; k < 13; k++){
                dp[i][(k * 10 + c) % 13] += dp[i-1][k];
                dp[i][(k * 10 + c) % 13] %= MOD;
            }
        }
    }
    cout << dp[n-1][5] << endl;
}
