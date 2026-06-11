#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, m, h[100000], a, b, ans;
    vector<int> conect[100000];
    bool best;

    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) {
        cin >> h[i];
    }
    for ( int i = 0; i < m; i++ ) {
        cin >> a >> b;
        a--;
        b--;

        conect[a].push_back(b);
        conect[b].push_back(a);
    }

    ans = 0;
    for ( int i = 0; i < n; i++ ) {
        best = true;

        for ( int j = 0; j < conect[i].size(); j++ ) {
            if ( h[i] <= h[conect[i][j]] ) {
                best = false;
            }
        }

        ans += best;
    }

    cout << ans << endl;

    return (0);
}