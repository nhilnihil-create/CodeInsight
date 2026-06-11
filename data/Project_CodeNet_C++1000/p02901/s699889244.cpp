#include <bits/stdc++.h>

using namespace std;
#define  ll long long
#define ld long double
#define f first
#define s second
const int N = 1e3+5;

int n , m , a[N] , b[N] , num[N] , dp[N][1<<12];

int solve(int i , int msk)
{
    if (i > m)
    {
        int c = __builtin_popcount(msk);
        if (c==n) return 0;
        return (int)1e9;
    }

    if (dp[i][msk] != -1)
        return dp[i][msk];

    int ans = solve(i+1 , msk);
    ans = min(ans , a[i] + solve(i+1,msk|num[i]));
    return dp[i][msk] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        cin >> a[i] >> b[i];
        for(int j=1; j<=b[i]; j++)
        {
            ll x;
            cin >> x;
            x--;
            num[i] |= (1<<x);
        }
    }

    memset(dp , -1 , sizeof(dp));

    int ans = solve(1,0);
    if (ans >= (int)1e9) cout << "-1\n";
    else cout << ans << "\n";
	//
  
    return 0;
}