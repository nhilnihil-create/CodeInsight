#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<int> ans(n);
    rep(i,n) {
        vector<int> dist(n,INF);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v-1 >= 0) {
                if (dist[v-1] == INF) {
                    dist[v-1] = dist[v]+1;
                    q.push(v-1);
                }          
            }
            if (v+1 <= n-1) {
                if (dist[v+1] == INF) {
                    dist[v+1] = dist[v]+1;
                    q.push(v+1);
                }
            }
            if (v == x) {
                if (dist[y] == INF) {
                    dist[y] = dist[x]+1;
                    q.push(y);
                }
            }
            if (v == y) {
                if (dist[x] == INF) {
                    dist[x] = dist[y]+1;
                    q.push(x);
                }
            }
        }
        rep(j,n) ans[dist[j]]++;
    }
    rep(i,n) ans[i] /= 2;
    for (int i = 1; i <= n-1; i++) printf("%d\n", ans[i]);
    return 0;
}