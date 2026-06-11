#include <bits/stdc++.h>
using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define int long long
  #define endl "\n"
  const int N = 200005;


const int INF = (1LL << 30) - 1;
const int MOD = 1000000007;
int32_t main()
{


    IOS

    
    int n,m;

    cin >> n >> m;

    vector<int> dp((1<<n));


    vector<int> cost(m);

    // dp[mask] denotes the minimum cost to open 
    //  the treasure box represented by set bits
    //

    vector<set<int>> b;


    for(int i = 0; i< m; i++)
    {
        cin >> cost[i];

        int x;
        cin >> x;

        set<int> v;

        for(int i = 1; i <= x; i++)
        {   
            int y;
            cin >> y;
            v.insert(y);
        }
        b.push_back(v);
    }


    for(int i = 0; i < (1<<n); i++)
    {
        dp[i] = INF;
    }

    dp[0] = 0;


    for(int i = 0; i < b.size(); i++)
    {
        for(int mask = 0; mask < (1<<n); mask++)
        {
            int target = mask;
            for(auto j : b[i])
            {
                target |= (1<<(j-1));
                dp[target] = min(dp[target],dp[mask] + cost[i]);
            }
        }
    }




    cout << ((dp[(1<<n)-1] == INF)?-1 : dp[((1<<n)-1)]) << endl;


    
    return 0;
}

