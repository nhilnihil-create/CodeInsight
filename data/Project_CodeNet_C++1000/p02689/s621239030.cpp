#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "[(" << __LINE__ << ") " << (#x) << "]: " << x << endl;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n];
    for (int& e: a) cin >> e;

    vector<vector<int>> g(n);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        bool flag = true;
        for (int e : g[i])
            if (a[e] >= a[i])
                flag = false;

        cnt += flag;
    }
    cout << cnt << "\n";
}
