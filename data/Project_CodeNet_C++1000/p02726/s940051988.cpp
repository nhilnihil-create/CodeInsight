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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> ans(N);
    rep(i, N) {
        for (ll j = i + 1; j < N; j++) {
            ll mi = min(min(abs(j - i), abs(X - i - 1) + 1 + abs(Y - j - 1)),
                        abs(Y - i - 1) + 1 + abs(X - j - 1));
            ans[mi - 1] += 1;
        }
    }
    rep(i, N - 1) { cout << ans[i] << endl; }
    return 0;
}
