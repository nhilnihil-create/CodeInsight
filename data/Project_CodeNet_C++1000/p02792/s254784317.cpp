#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ii digits(int N)
{
    int a, b = N % 10;

    while (N)
    {
        a = N % 10;
        N /= 10;
    }

    return { a, b };
}

ll solve(ll N)
{
    ll ans = 0;
    map<ii, ll> hs;

    for (ll i = 1; i <= N; ++i)
        hs[digits(i)]++;

    for (int a = 1; a <= 9; ++a)
        for (int b = 1; b <= 9; ++b)
            ans += hs[ii(a, b)] * hs[ii(b, a)];

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
