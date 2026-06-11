#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 200010 };
const ll MOD { 1000000007 }, oo { 1LL << 62 };

ll solve(ll N)
{
    if (N == 2)
        return 1;

    set<ll> xs;

    xs.insert(N - 1);

    for (ll i = 2; i * i <= (N - 1); ++i)
        if ((N - 1) % i == 0)
        {
            xs.insert(i);
            xs.insert((N - 1) / i);
        }

#ifdef DEBUG
    cout << "xs = ";
    for (auto x : xs)
        cout << x << ' ';
    cout << endl;
#endif

    xs.insert(N);

    for (ll i = 2; i * i <= N; ++i)
        if (N % i == 0)
        {
            auto k = N / i;

            while (k % i == 0)
                k /= i;

            if (k % i == 1)
                xs.insert(i);
        }

#ifdef DEBUG
    cout << "xs = ";
    for (auto x : xs)
        cout << x << ' ';
    cout << endl;
#endif


    return xs.size();
}

int main()
{
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    auto ans = solve(N);

    cout << ans << '\n';

    return 0;
}
