#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    vector h(n,0);
    for (int i=0; i<n; i++) cin >> h[i];

    vector<vector<int>> g(n);
    for (int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        bool f = true;
        for (const auto &item : g[i]) {
            if (h[i] <= h[item]) f = false;
        }
        if (f) ans++;
    }

    cout << ans << endl;
}