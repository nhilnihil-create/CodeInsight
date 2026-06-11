#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int n, m, dp[1005][1 << 12];
vector<pair<int, int>>v;
int solve(int idx, int mask){
    if(__builtin_popcount(mask) == n)
        return 0;
    else if(idx >= m)
        return 1e9;
    if(dp[idx][mask] != -1)
        return dp[idx][mask];
    int ans = 1e9;
    ans = min(ans, solve(idx + 1, mask));
    ans = min(ans, solve(idx + 1, mask | v[idx].second) + v[idx].first);
    dp[idx][mask] = ans;
    return ans;
}
int main()
{
    Hello
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int cost, elements, bitmask = 0;
        cin >> cost >> elements;
        for(int j = 0; j < elements; j++){
            int numb;
            cin >> numb;
            bitmask = bitmask | (1 << (numb - 1));
        }
        v.push_back({cost, bitmask});
    }
    int ans = solve(0, 0);
    if(ans >= 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}