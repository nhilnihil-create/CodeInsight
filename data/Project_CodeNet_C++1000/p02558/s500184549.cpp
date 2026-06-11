#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    for (int i = 0; i < Q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            d.merge(u, v);
        else
            cout << d.same(u, v) << '\n';
    }

    return 0;
}
