#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

vector<int> digits(int n)
{
    vector<int> ds;

    do {
        ds.push_back(n % 10);
        n /= 10;
    } while (n);

    reverse(ds.begin(), ds.end());

    return ds;
}
int solve(int N, const vector<ii>& xs)
{
    int a, b;

    if (N == 1)
    {
        a = 0;
        b = 9;
    } else if (N == 2)
    {
        a = 10;
        b = 99;
    } else
    {
        a = 100;
        b = 999;
    }

    for (int n = a; n <= b; ++n)
    {
        auto ds = digits(n);

        bool ok = true;

        for (auto x : xs)
        {
            auto i = x.first - 1, v = x.second;

            if (ds[i] != v)
            {
                ok = false;
                break;
            }
        }

        if (ok)
            return n;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<ii> xs(M);

    for (int i = 0; i < M; ++i)
        cin >> xs[i].first >> xs[i].second;

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
