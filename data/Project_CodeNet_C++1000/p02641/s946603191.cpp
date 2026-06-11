#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long X, long long N, std::set<long long> p)
{
    ll m = INT_MAX;
    ll ans = X;

    for (ll i = 0; i <= 101; i++)
    {
        if (p.count(i) == 0)
        {
            if (m > abs(X - i))
            {
                m = abs(X - i);
                ans = i;
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    long long X;
    scanf("%lld", &X);
    long long N;
    scanf("%lld", &N);
    std::set<long long> p;
    for (int i = 0; i < N; i++)
    {
        ll a;
        scanf("%lld", &a);
        p.insert(a);
    }
    solve(X, N, p);
    return 0;
}
