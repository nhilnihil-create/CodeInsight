#include <bits/stdc++.h>
using namespace std;
int n, m, h[100005], ans=0;
vector<int> r[100005];
int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> h[i];
    for (int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    bool ok=1;
    for (int i=1; i<=n; i++) {
        ok=1;
        for (int j=0; j<r[i].size(); j++) {
            if (h[i]<=h[r[i][j]]) ok=0;
        }
        if (ok) ans++;
    }
    
    cout << ans;
}