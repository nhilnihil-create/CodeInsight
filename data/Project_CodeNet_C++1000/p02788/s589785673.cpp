#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

template <typename T>
struct BIT {
    int siz;
    vector<T> bit;

    BIT(int N) : siz(N + 1), bit(siz) {}

    void add(int k, T x) {
        while (k < siz) {
            bit[k] += x;
            k += (k & -k);
        }
    }

    T sum(int k) {
        T res(0);
        while (k > 0) {
            res += bit[k];
            k -= (k & -k);
        }
        return res;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, D, A;
    cin >> N >> D >> A;
    vector<pll> p(N);
    for (int i = 0; i < N; ++i)
        cin >> p[i].first >> p[i].second;
    sort(p.begin(), p.end());

    BIT<ll> bit1(N + 1), bit2(N + 1);

    auto add = [&](int a, int b, ll x) -> void {
        bit1.add(a, -x * (a - 1));
        bit1.add(b + 1, x * b);
        bit2.add(a, x);
        bit2.add(b + 1, -x);
    };

    auto getsum = [&](int k) -> ll {
        return bit1.sum(k) + bit2.sum(k) * k;
    };

    for (int i = 0; i < N; ++i)
        bit1.add(i + 1, p[i].second);

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll val = getsum(i + 1) - getsum(i);
        if (val <= 0)
            continue;
        ll cnt = (val + A - 1) / A;
        int idx = lower_bound(p.begin(), p.end(), pll{p[i].first + 2 * D, INT_MAX}) - p.begin();
        add(i + 1, idx, -cnt * A);
        ans += cnt;
    }
    cout << ans << '\n';

    return 0;
}
