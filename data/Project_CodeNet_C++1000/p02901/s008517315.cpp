#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e3 + 2;
int n, m, price[A], masks[8888];
ll dp[A][8888];
ll solve(int ind, int mask) {
    if (ind == m)
        return (mask == (1 << n) - 1 ? 0 : 1e18);
    if (~dp[ind][mask])
        return dp[ind][mask];
    ll val = solve(ind + 1, mask);
    val = min(val, solve(ind + 1, mask | masks[ind]) + price[ind]);
    return dp[ind][mask] = val;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> price[i] >> x;
        while(x--)
            cin >> y, masks[i] |=(1 << (y - 1));
    }
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0);
    cout << (ans >= 1e18 ? -1 : ans);
    return 0;
}