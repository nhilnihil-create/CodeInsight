#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

class UFDS {
public:
    std::vector<ll> size, ps;
    ll ans;
    UFDS(ll N) : size(N + 1, 1), ps(N + 1), ans(1) {
        iota(ps.begin(), ps.end(), 0);
    }

    ll find_set(ll x) const {
        return x == ps[x] ? x : find_set(ps[x]);
    }

    bool same_set(ll x, ll y) {
        return find_set(x) == find_set(y);
    }

    void union_set(ll x, ll y)
    {
        if (same_set(x, y)) return;

        ll p = find_set(x);
        ll q = find_set(y);

        if (size[p] < size[q])
            std::swap(p, q);

        ps[q] = p;
        size[p] += size[q];

        ans = max(ans, size[p]);
    }
};

int main()
{
    ll n, m;
    cin >> n >> m;

    UFDS union_find(n);

    while(m--)
    {
        ll a, b;
        cin >> a >> b;

        union_find.union_set(a, b);
    }

    cout << union_find.ans << '\n';


    return 0;
}
