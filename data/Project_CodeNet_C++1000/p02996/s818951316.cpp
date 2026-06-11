#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

string solve(int N, vector<ii>& xs)
{
    sort(xs.begin(), xs.end());

    ll t = 0;

    for (auto x : xs)
    {
        auto b = x.first, a = x.second;

        if (t + a > b)
            return "No";

        t += a;
    }

    return "Yes";
}

int main()
{
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<ii> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i].second >> xs[i].first;

    auto ans = solve(N, xs);

    cout << ans << '\n';

    return 0;
}
