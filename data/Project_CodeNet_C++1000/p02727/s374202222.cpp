#include <bits/stdc++.h>

using ll = long long int;
using P = std::pair<int, int>;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int x, y, a, b, c;

    std::cin >> x >> y >> a >> b >> c;

    std::vector<ll> p(a), q(b), r(c);

    rep(i, a)
    {
        std::cin >> p[i];
    }
    rep(i, b)
    {
        std::cin >> q[i];
    }
    std::sort(std::begin(p), std::end(p), std::greater<>());
    std::sort(std::begin(q), std::end(q), std::greater<>());

    std::vector<ll> pq;

    rep(i, x)
    {
        pq.push_back(p[i]);
    }
    rep(i, y)
    {
        pq.push_back(q[i]);
    }
    std::sort(std::begin(pq), std::end(pq), std::greater<>());
    for (int i = 1; i < pq.size(); ++i)
        pq[i] += pq[i - 1];
    rep(i, c)
    {
        std::cin >> r[i];
    }
    std::sort(std::begin(r), std::end(r), std::greater<>());

    for (int i = 1; i < r.size(); ++i)
        r[i] += r[i - 1];

    ll ans = pq[x + y - 1];

    for (int i = 0; i < x + y - 1 && i < c; ++i)
    {
        ans = std::max(ans, pq[x + y - i - 2] + r[i]);
    }

    if (x + y <= c)
        ans = std::max(ans, r[x + y - 1]);

    std::cout << ans << std::endl;

    return 0;
}