#include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint n;
vector<int> u, v;

lint vertice_count() {
    lint res = 0;
    for (lint i = 0; i < n; i++) {
        res += (i + 1 - 0) * (n - i);
    }
    return res;
}

lint edge_count(int l, int r) {
    if (l > r) {
        swap(l, r);
    }
    return 1LL * (l + 1 - 0) * (n - r);
}

lint edges_count() {
    lint res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += edge_count(u[i], v[i]);
    }
    return res;
}

lint solve() {
    return vertice_count() - edges_count();
}

int main() {
    cin >> n;
    u.resize(n - 1);
    v.resize(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    cout << solve() << endl;
}