#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX_E = 45;
const int MAX_V = 10;
const int INF = INT32_MAX;
struct edge {int to, cost; };
typedef pair<int, int> P;
vector<edge> G[MAX_V];
vector<string> result;

int main() {
    int n;
    while(1) {
        cin >> n;
        if (n == 0) break;
        int max_v = -1;
        for (int i = 0; i <= MAX_V; i++)G[i].clear();
        for (int i = 0; i < n; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            edge e, e1;
            e.to = to;
            e.cost = cost;
            G[from].push_back(e);
            e1.to = from;
            e1.cost = cost;
            G[to].push_back(e1);
            max_v = max(max(max_v, from), to);
        }
        max_v++;

        int dps[max_v];
        for(int i = 0; i < max_v; i++) {
            int d[max_v];
            fill(d, d + max_v, INF);
            priority_queue<P, vector<P>, greater<P>> que;
            d[i] = 0;
            que.push(P(0, i));
            while(!que.empty()) {
                P p = que.top();
                que.pop();
                int v = p.second;
                if(p.first > d[v]) continue;
                for(int j = 0; j < G[v].size(); j++) {
                    edge e = G[v][j];
                    if(d[e.to] > d[v] + e.cost) {
                        d[e.to] = d[v] + e.cost;
                        que.push(P(d[e.to], e.to));
                    }
                }
            }


            int sum = 0;
            for(int j = 0; j < max_v; j++) {
                sum += d[j];
            }

            dps[i] = sum;
        }

        int min_i = 0;
        for(int i = 1; i < max_v; i++) {
            if(dps[min_i] > dps[i]) {
                min_i = i;
            }
        }

        result.push_back(to_string(min_i) + " " + to_string(dps[min_i]));
    }

    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}