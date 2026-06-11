#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> dp(h + 1);
    vector<int> a(n);   
    vector<int> b(n);
    rep(i, n)
    {
        cin >> a[i];
        cin >> b[i];
    }

    rep(j, h + 1) dp[j] = (1 << 30);
    dp[0] = 0;
    
    rep(j, h)
    {
        if( dp[j] == (1 << 30) ) continue;
        rep(i, n)
        {
            int nh = min(h, j + a[i]);
            dp[nh] = min(dp[nh], dp[j] + b[i]);
        }
    }
    cout << dp[h];
}