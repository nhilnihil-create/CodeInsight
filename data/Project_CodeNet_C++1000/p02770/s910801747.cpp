#include <bits/stdc++.h>
#define isz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()

using vi = std::vector<int>;
using ll = long long;

ll solve(vi d, const int n, const int x, const int m) {
    for (auto &it : d) it %= m;
    if (isz(d) > n) d.resize(n);
    int nZeros = 0;
    for (auto &it : d) nZeros += (it == 0);
    ll s = std::accumulate(all(d), 0LL);
    int last = n-2;
    int q = last / isz(d);
    int r = last % isz(d);
    ll y = x + q * s;
    nZeros *= q;
    for (int i = 0; i <= r; i++) y += d[i], nZeros += (d[i] == 0);
    ll nLess = y / m;
    return n-1 - nLess - nZeros;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int k, q; std::cin >> k >> q;
    vi d(k);
    for (auto &it : d) std::cin >> it;
    while (q--) {
        int n, x, m; std::cin >> n >> x >> m;
        std::cout << solve(d,n,x%m,m) << "\n";
    }
    return 0;
}