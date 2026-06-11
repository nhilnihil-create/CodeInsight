#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(int N, vector<int>& as, vector<int>& bs)
{
    ll ans = 0;

    for (int i = 0; i < N; ++i)
    {
        auto k = min(as[i], bs[i]);

        ans += k;
        as[i] -= k;
        bs[i] -= k;

        auto r = min(as[i + 1], bs[i]);

        ans += r;
        as[i + 1] -= r;
        bs[i] -= r;
    }
 
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> as(N + 1), bs(N);

    for (int i = 0; i <= N; ++i)
        cin >> as[i];

    for (int i = 0; i < N; ++i)
        cin >> bs[i];

    auto ans = solve(N, as, bs);

    cout << ans << '\n';

    return 0;
}
