#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const vector<ii> xs {
    { 0, 0 },
    { 20, 18 },
    { 11, 9 },
    { 4, 3 },
    { 13, 9 },
    { 14, 9 },
    { 5, 3 },
    { 16, 9 },
    { 17, 9 },
    { 2, 1 },
}; 

ll solve(const vector<ii>& ds)
{
    ll ans = 0;
    stack<ll> rs;

    for (auto p : ds)
    {
        auto d = p.first;
        auto c = p.second;

        if (d == 0)
        {
            ans += c;
            continue;
        }

        auto qtd = xs[d].first;
        auto n = xs[d].second;
        auto k = c / n;
        auto r = c % n;

        if (r == 0)
        {
            r = n;
            --k;
        }
//cout << "qtd = " << qtd << ", k = " << k << ", r = " << r << ", d = " << d << '\n';
        ans += qtd * k;

        while (r--)
            rs.push(d);
    }

    while (rs.size() > 1)
    {
        auto x = rs.top();
        rs.pop();
 
        auto y = rs.top();
        rs.pop();

        auto z = x + y;

        if (z > 9)
        {
            rs.push(z / 10);
            rs.push(z % 10);
        } else
            rs.push(z);

        ++ans;
    } 

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int M;
    cin >> M;

    vector<ii> ds(M);

    for (int i = 0; i < M; ++i)
    {
        ll d, c;
        cin >> d >> c;

        ds[i] = ii(d, c);
    }

    auto ans = solve(ds);

    cout << ans << '\n';

    return 0;
}
