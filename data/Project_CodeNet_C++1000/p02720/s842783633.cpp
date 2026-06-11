#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(size_t K)
{
    set<ll> xs, ys;

    for (int i = 1; i < 10; ++i)
        xs.insert(i);

    while (xs.size() < K)
    {
        ys.clear();

        for (auto x : xs)
        {
            ys.insert(x);

            int d = x % 10;

            ys.insert(10*x + d);

            if (d > 0)
                ys.insert(10*x + (d - 1));

            if (d < 9)
                ys.insert(10*x + (d + 1));
        }

        ys.swap(xs);
    }

    auto it = xs.begin();

    while (--K)
        ++it;

    return *it;
}

int main()
{
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    auto ans = solve(K);

    cout << ans << '\n';

    return 0;
}
