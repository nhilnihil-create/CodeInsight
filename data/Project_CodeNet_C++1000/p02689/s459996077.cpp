#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m, h[100001], ma[100001];
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        ma[i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ma[a] = max(ma[a], h[b]);
        ma[b] = max(ma[b], h[a]);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += h[i] > ma[i];
    }
    cout << ans << endl;
    return 0;
}