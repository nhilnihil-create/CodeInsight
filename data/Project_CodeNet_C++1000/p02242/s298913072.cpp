#include <bits/stdc++.h>

using namespace std;

#define Vi vector<int>
#define FOR(i,s,e) for (int i=s; i<e; i++)
#define ITER(v) v.begin(), v.end()

constexpr int N_MAX = 100;

int weight[N_MAX][N_MAX];
int dis[N_MAX];

void set_shortest_distance(const int n) {
    bool ismember[n] = {false};

    int newmember = 0;
    dis[newmember] = 0;
    ismember[newmember] = true;

    FOR(t,0,n-1) {
        FOR(i,0,n) {
            if (weight[newmember][i] < 0) { continue; }
            if (ismember[i]) { continue; }
            const int d = dis[newmember] + weight[newmember][i];
            if (dis[i] < 0 || d < dis[i]) {
                dis[i] = d;
            }
        }
        int min_i = -1, min_d = -1;
        FOR(i,0,n) {
            if (dis[i] < 0) { continue; }
            if (ismember[i]) { continue; }
            if (min_d < 0 || dis[i] < min_d) {
                min_i = i;
                min_d = dis[i];
            }
        }
        newmember = min_i;
        ismember[newmember] = true;
        //cout << "#" << min_i << " " << min_d << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    FOR(i,0,n) {
        dis[i] = -1;
        FOR(j,0,n) {
            weight[i][j] = -1;
        }
    }

    int u, k, v, c;
    FOR(i,0,n) {
        cin >> u >> k;
        FOR(j,0,k) {
            cin >> v >> c;
            weight[u][v] = c;
        }
    }

    set_shortest_distance(n);

    for (int i = 0; i < n; ++i) {
        cout << i << " " << dis[i] << endl;
    }

    return 0;
}