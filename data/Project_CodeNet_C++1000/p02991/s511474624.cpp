#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(3 * n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        to[3*u+0].push_back(3*v+1);
        to[3*u+1].push_back(3*v+2);
        to[3*u+2].push_back(3*v+0);
    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    int INF = 1001001001;
    vector<int> d(3*n, INF);
    d[3*s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(make_pair(0, 3*s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int dist = p.first;
        int v = p.second;
        if(d[v] < dist)continue;
        for(int t : to[v]){
            if(d[t] > d[v] + 1){
                d[t] = d[v] + 1;
                que.push(make_pair(d[t], t));
            }
        }
    }
    if(d[3*t] == INF)cout << -1 << endl;
    else cout << d[3*t] / 3 << endl;
}