#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

bool ok(ll m, ll N, ll K, vector<ll>& as, vector<ll>& fs)
{
    ll ops = 0;

    for (int i = 0; i < N; ++i)
    {
        auto t = m / fs[i];

        ops += (as[i] > t ? as[i] - t : 0);
    }

    return ops <= K;
}

ll solve(ll N, ll K, vector<ll>& as, vector<ll>& fs)
{
    sort(as.begin(), as.end());
    sort(fs.begin(), fs.end(), greater<ll>());
 
    ll a = 0, b = 1000000000010, ans = b;

    while (a <= b)
    {
        auto m = a + (b - a)/2;

        if (ok(m, N, K, as, fs))
        {
            ans = m;
            b = m - 1;
        } else
            a = m + 1;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;

    vector<ll> as(N), fs(N);

    for (int i = 0; i < N; ++i)
        cin >> as[i];

    for (int i = 0; i < N; ++i)
        cin >> fs[i];

    auto ans = solve(N, K, as, fs);

    cout << ans << '\n';

    return 0;
}
