#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m, ans;
    ans = 0;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    int a, b;
    vector<int>g(n,1);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        if (h[a - 1] <= h[b - 1]) {
            g[a - 1] = 0;
        }
        if (h[a - 1] >= h[b - 1]) {
            g[b - 1] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        ans += g[i];
    }
    cout << ans << endl;

}
