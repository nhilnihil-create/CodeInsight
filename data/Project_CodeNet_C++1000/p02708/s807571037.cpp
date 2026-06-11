#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define SORT(c) sort(ALL((c)))
#define debug(x)                 \
    do {                         \
        std::cout << #x << ": "; \
        view(x);                 \
    } while (0)

template <typename T>
void view(T e) {
    std::cout << e << std::endl;
}
template <typename T>
void view(const std::vector<T>& v) {
    for (const auto& e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>>& vv) {
    for (const auto& v : vv) {
        view(v);
    }
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    for (ll i = K; i <= (N + 1); i++) {
        ll mi = i * (i - 1) / 2;
        ll ma = 0;
        rep(j, i) { ma += N - j; }
        ma = i * (2 * (N - i + 1) + (i - 1)) / 2;
        ans += (ma - mi + 1) % (1000000000 + 7);
    }
    cout << ans % (1000000000 + 7) << endl;
    return 0;
}
