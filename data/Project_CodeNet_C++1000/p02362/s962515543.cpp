#include <bits/stdc++.h>
using namespace std;

bool bellman_ford(const int v, const int s,
                  const vector<pair<pair<int, int>, int64_t>>& g,
                  vector<int64_t>& cost)
{
    const int64_t inf = 1LL << 60;
    cost[s] = 0;
    for (auto i = 0; i < v; i++) {
        for (auto & elm : g) {
            if(cost[elm.first.first] == inf) continue;
            if(cost[elm.first.second] > cost[elm.first.first] + elm.second) {
                if(i == v - 1) return true; // 負の閉路がある
                cost[elm.first.second] = cost[elm.first.first] + elm.second;
            }
        }
    }
    return false;
}

int main(){
    int v, e, r; cin >> v >> e >> r;
    vector<pair<pair<int, int>, int64_t>> g;
    const int64_t inf = 1LL << 60;
    vector<int64_t> cost(v, inf);
    for (auto i = 0; i < e; i++) {
        int s, t, d; cin >> s >> t >> d;
        g.emplace_back(make_pair(s, t), d);
    }
    if(bellman_ford(v, r, g, cost)) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (auto & elm : cost)
        cout << (elm == inf ? "INF" : to_string(elm)) << endl;
    return 0;
}
