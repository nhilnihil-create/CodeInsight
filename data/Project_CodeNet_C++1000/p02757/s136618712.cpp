#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define read(a) scanf("%d", &a)
#define readl(a) scanf("%lld", &a)
#define reads(a) scanf("%s", a)
#define readf(a) scanf("%lf", &a)
#define readc(a) scanf("%c", &a)
#define debug(a, b) printf("%s = %d\n", a, b)
#define debug1(a, i, b) printf("%s[%d] = %d", a, i, b)
#define show(a) putchar(a)
#define pb emplace_back
#define mk make_pair
#define _rand mt19937 RAND(time(0))
#define REP(i,a,n) for(int i=a;i<=n;++i)
#define mem(a) memset(a, 0, sizeof(a))
#define Buff ios::sync_with_stdio(false)
typedef long long ll;
typedef long long LL;
typedef int Int;
typedef double db;
using namespace std;
const int INF = 1e9 + 7;
const int N = 2e5 + 7;
const int M = 5e6 + 7;
char s[N];
ll dp[N];
signed main()
{
    int n, p;
    read(n); read(p);
    reads(s + 1);

    ll ans = 0;
    if(p == 2 || p == 5)
    {
        for(int i = n; i; i--)
            if((s[i]-'0') % p == 0)
                ans += 1ll*i;
    }
    else
    {
        ll d = 1, x = 0;
        for(int i = n; i; i--)
        {
            x += (s[i]-'0') * d;
            x %= p;

            d *= 10;
            d %= p;

            ans += dp[x];
            dp[x]++;
            if(x == 0) ans++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
/**

**/

