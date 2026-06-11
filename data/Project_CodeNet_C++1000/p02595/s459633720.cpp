#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long D, std::vector<long long> X, std::vector<long long> Y)
{

    ll ans = 0;
    for (ll i = 0; i < N; i++)
    {
        if (X[i] * X[i] + Y[i] * Y[i] <= D * D)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

signed main()
{
    long long N;
    scanf("%lld", &N);
    long long D;
    scanf("%lld", &D);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &X[i]);
        scanf("%lld", &Y[i]);
    }
    solve(N, D, std::move(X), std::move(Y));
    return 0;
}
