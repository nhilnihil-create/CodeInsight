#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod=1e9+7;
int power(int a,int b)
{
    if(a==1 || b==0)
        return 1;
    if(b==1)
        return a;
    int x=power(a,b/2);
    if(b%2==0)
        return ((x%mod)*(x%mod))%mod;
    return (((x%mod)*(x%mod))%mod * a)%mod;
}
void solve()
{
    int n, k, sum = 0;
    cin >> n >> k;
    vector<int> dp(k + 1, 0);
    for (int i = k; i >= 1; i--)
    {
        dp[i] = power(k / i, n);
        for (int j = i + i; j <= k; j+=i)
        {
            dp[i] = dp[i] - dp[j] + mod;
            while (dp[i] >= mod)
                dp[i] -= mod;
        }
        sum += dp[i]*i;
        while (sum >= mod)
            sum -= mod;
    }
    cout<<sum;
}

int32_t main()
{
    solve();
    return 0;
}
