#include<bits/stdc++.h>
#define ll long long
#define S second
#define F first

using namespace std;

const int N = 2e5 + 15, M = 2e5 + 5;

#define arr(t, n, s, e) t _##n[e-s+1], *n= _##n+(-s);

ll n, k, arr[3];
char str[N], alpha[] = "rspx", opp[] = "sprx";
ll dp[N][5];

ll solve(int ind, int prv)
{
    if(ind >= n) return 0;
    ll &ret = dp[ind][prv];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(prv != i) ret = max(ret, solve(ind + k, i) + arr[i] * (str[ind] == opp[i]));
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%lld%lld%lld%lld%lld%s", &n, &k, arr, arr + 1, arr + 2, str);
    ll ans = 0;
    for(int i = 0 ; i < k ; i++) ans += solve(i, 3);
    printf("%lld\n", ans);
    return 0;
}