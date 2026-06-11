#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 


const long long mod = 1000000007;
long long dp[100005];

long long power(long long a, long long b)
{
    if (b == 0)
    {
        return 1LL;
    }
    if (b == 1)
    {
        return 1LL*a%mod;
    }
    if (b%2 == 0)
    {
        long long  x = power (a, b/2);
        x = (x*x)%mod;
        return x;
    }
    else if (b != 1 && b!= 0 && b%2 != 0)
    {
        long long  x = power(a, (b-1)/2);
        x = (x*x)%mod;
        return (x*a)%mod;
    }
}

int main()
{ 
    long long  n, k;
    cin >> n >> k;
    
    for (int i = k; i >= 1; i--)
    {
        dp[i] = power(k/i, n);
        for (int j = 2*i; j <= k; j+=i)
        {
            dp[i] = dp[i] - dp[j];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans = (ans + (dp[i]*i)%mod)%mod;
    }

    cout << ans%mod;
    return 0;
    
}