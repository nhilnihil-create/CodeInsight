#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::vector<long long> A)
{
    sort(A.begin(), A.end());
    if (A[0] == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll ans = 1;
    for (ll i = 0; i < N; i++)
    {
        if (ans > (ll)1e18 / A[i])
        {
            ans = -1;
            break;
        }
        ans *= A[i];
    }
    cout << ans << endl;
}

signed main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    solve(N, std::move(A));
    return 0;
}
