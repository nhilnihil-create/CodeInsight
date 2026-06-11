#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000
#define MAX_M 2000

struct Edge{
    int v[2], cost;
    Edge(){}
    Edge(int a, int b, int c) {
        v[0] = a; v[1] = b; cost = c;
    }
};

int n, m, r, d[MAX_N];
Edge E[MAX_M];

void shortest_path(){
    fill(d, d + n, INT_MAX);
    d[r] = 0;
    for(int cnt = 0; ; cnt++){
        if(cnt == n){
            cout << "NEGATIVE CYCLE" << endl;
            return;
        }
        bool update = true;
        for(int j = 0; j < m; j++){
            int s = E[j].v[0], t = E[j].v[1], w = E[j].cost;
            if(d[s] != INT_MAX && d[s] + w < d[t]){
                d[t] = d[s] + w;
                update = false;
            }
        }
        if(update) break;
    }
    for(int i = 0; i < n; i++){
        cout << (d[i] == INT_MAX ? "INF" : to_string(d[i])) << endl;
    }
    return;
}

int main(){
    cin >> n >> m >> r;
    for(int i = 0; i < m; i++){
        int s, t, d;
        cin >> s >> t >> d;
        E[i] = Edge(s, t, d);
    }
    shortest_path();
    return 0;
}
