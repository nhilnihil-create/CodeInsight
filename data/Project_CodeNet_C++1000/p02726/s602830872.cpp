#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> ans(n);
    rep(ov,n) {

        vector<int> dist(n, -1);
        queue<int> que;

        dist[ov] = 0;
        que.push(ov);

        auto f = [&](int v, int d) {
            if (dist[v] != -1) return;
            dist[v] = d + 1;
            que.push(v);
        };
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (v-1 >= 0) f(v-1, dist[v]);
            if (v+1 < n) f(v+1, dist[v]);
            if (v == x) f(y, dist[v]);
            if (v == y) f(x, dist[v]);
        }

        rep(i,n) {
            ans[dist[i]]++;
        }
    }

    rep(i,n) ans[i] /= 2;

    for (int i = 1; i < n; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}