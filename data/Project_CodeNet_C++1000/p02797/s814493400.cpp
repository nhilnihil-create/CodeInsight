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
    ll N, K, S;
    cin >> N >> K >> S;

    vector<ll> ans(K, S);
    ll tmp = S == 1000000000 ? 1 : S + 1;
    rep(i, N - K) { ans.push_back(tmp); }
    rep(i, N - 1) { cout << ans[i] << " "; }
    cout << ans[N - 1] << endl;
    return 0;
}
