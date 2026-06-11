#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long K, std::vector<long long> P, std::vector<long long> C)
{
    ll ans = -INT_MAX;
    for (ll i = 0; i < N; i++)
    {
        ll u = i;
        ll cycle_sum = 0;
        ll cycle_num = 0;
        for (ll j = 0; j < K; j++)
        {
            cycle_num++;
            cycle_sum += C[u];
            u = P[u];
            if (u == i)
            {
                break;
            }
        }

        u = i;
        ll res = 0;
        for (ll j = 0; j < K; j++)
        {
            res += C[u];
            ans = max(ans, res);
            ans = max(ans, res + cycle_sum * ((K - j - 1) / cycle_num));
            u = P[u];
            if (u == i)
            {
                break;
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> P(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &P[i]);
        P[i]--;
    }
    std::vector<long long> C(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &C[i]);
    }
    solve(N, K, std::move(P), std::move(C));
    return 0;
}