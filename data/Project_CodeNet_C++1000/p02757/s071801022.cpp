#include <bits/stdc++.h>
using namespace std;
#define elif else if
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG(x) cout << (x) << endl

ll n, p;
string s;
ll tmp[10005] = {0};

int main()
{
    scanf("%lld %lld", &n, &p);
    cin >> s;
    tmp[0] = 1;
    ll ans = 0;
    ll now = 0;
    ll times = 1;
    if (p == 2 || p == 5)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % p == 0)
            {
                ans += i + 1;
            }
        }
    }
    else
    {
        for (int i = n - 1; i >= 0; i--)
        {
            now += (s[i] - '0') * times;
            times *= 10;
            now %= p;
            times %= p;
            ans += tmp[now];
            tmp[now] += 1;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
