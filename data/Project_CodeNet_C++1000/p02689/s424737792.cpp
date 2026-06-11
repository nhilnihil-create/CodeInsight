#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    vector<int> good(n, 1);

    // vector<vector<int>> path(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if(h[a] >= h[b]) good[b] = 0;
        if(h[a] <= h[b]) good[a] = 0;
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        ans += good[i];
    }
    cout << ans << endl;
    return 0;
}