#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

vector<int> G[100010];

int d[3][100010];
int V;
typedef pair<int, int> P;
typedef pair<int, P> PP;
void dijkstra(int s) {
    priority_queue<PP, vector<PP>, greater<PP>> que;
    d[0][s] = 0;
    que.push({0, {s, 0}});
    while (!que.empty()) {
        PP p = que.top(); que.pop();
        
        int v = p.second.first;
        int state = p.second.second;
        int next_state = (state + 1) % 3;
        if (d[state][v] < p.first) continue;
        //cerr << p.first << " " << p.second.first << " " << p.second.second << endl;
        for(auto to: G[v]) {
            //cerr << "*" << to << " " << d[next_state][to] << endl;
            if (d[next_state][to] > d[state][v] + 1) {
                d[next_state][to] = d[state][v] + 1;
                que.push({d[next_state][to], {to, next_state}});
            }
        }
    }
}
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    V = N;
    cin >> N >> M;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        //G[v].push_back(u);
    }
    rep(i, 3) rep(j, 100010) d[i][j] = INF;
    int S, T; cin >> S >> T;
    S--; T--;
    dijkstra(S);
    if(d[0][T] == INF) {
        cout << "-1" << endl;
    } else {
        cout << d[0][T]/3 << endl;
    }

    return 0;
}
