#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/priority_queue.hpp>
typedef __gnu_pbds::priority_queue<int> pq;


int main(void) {
    int n, m; scanf("%d %d", &n, &m);
    int k; scanf("%d", &k);
    vector<int> x(k), y(k);
    vector<int> c(m, 0);
    vector<vector<int>> g(n);
    pq q;
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        x[i]--; y[i]--;
        g[x[i]].push_back(y[i]);
        c[y[i]]++;
    }
    vector<pq::point_iterator> v;
    for (int i = 0; i < m; ++i)
        v.push_back(q.push(c[i]));
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) q.modify(v[j], c[j] - 1);
        ans = max(ans, (int)g[i].size() + q.top());
        for (int j : g[i]) q.modify(v[j], c[j]);
    }
    printf("%d\n", ans);

    return 0;
}