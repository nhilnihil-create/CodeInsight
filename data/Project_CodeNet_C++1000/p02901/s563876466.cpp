#include <bits/stdc++.h>
#define int long long
using namespace std;
#define _READ freopen("input.txt", "r", stdin);
#define _FAST                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
int32_t main()
{
    //_READ
    int n, m;
    cin >> n >> m;
    int power = 1ll << n;
    vector<int> cost(power , 1e18); //keys->cost
    for (int temp = 0; temp < m; temp++)
    {
        int a, b;
        cin >> a >> b;
        int mask = 0;
        for (int i = 0; i < b; i++)
        {
            int input;
            cin >> input;
            input--;
            mask |= (1ll << input);
        }
        cost[mask] = min(cost[mask], a);
    }
    vector<vector<int>> items;
    for (int i = 1; i < (int)cost.size(); i++)
        if (cost[i] != 1e18)
            items.push_back({i, cost[i]});
    // weight, price
    n = items.size();

    vector<vector<int>> dp(n, vector<int>(power, 1e18));
    for(int i=0;i<n;i++)
        dp[i][0]=0;
    for (int i = 0; i < n; i++)
    {
        int weight = items[i][0];
        int price = items[i][1];
        if (i == 0)
        {
            dp[i][weight]=min(dp[i][weight],price);
            continue;
        }
        for(int j=0;j<power;j++)
        {
            int new_weight=j|weight;
            dp[i][new_weight]=min(dp[i][new_weight],dp[i-1][j]+price);
        }
        for(int j=0;j<power;j++)
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
    }
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,dp[i][power-1]);
    }
    if(ans==1e18)
        ans=-1;
    cout<<ans;
    return 0;
}
//16:54