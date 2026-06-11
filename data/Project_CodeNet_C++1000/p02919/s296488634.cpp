#include <bits/stdc++.h>

using namespace std;
using ll=int64_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using mii = map<int, int>;
using vi=vector<int>;
using vii=vector<vi>;
using vl=vector<ll>;
using vll=vector<vl>;
using tpi=tuple<int, int, int>;

int main() {
    using spi=multiset<pii>;

    int N;
    cin >> N;

    vi v(N + 1);
    for (auto i = 1; i <= N; i++) {
        int p;
        cin >> p;
        v[p] = i;
    }

    spi s;

    s.emplace(0, 0);
    s.emplace(0, 0);
    s.emplace(N + 1, N + 1);
    s.emplace(N + 1, N + 1);

    ll ans = 0;
    for (auto i = N; i >= 1; i--) {
        auto iter = s.emplace(v[i], i);

        auto r1 = next(iter, 1);
        auto r2 = next(iter, 2);
        auto l1 = prev(iter, 1);
        auto l2 = prev(iter, 2);
        ll tmp = ((*r2).first - (*r1).first) * (v[i] - (*l1).first);
        ans += i * tmp;
        tmp = ((*l1).first - (*l2).first) * ((*r1).first - v[i]);
        ans += i * tmp;
    }

    cout << ans << endl;
    return 0;
}
