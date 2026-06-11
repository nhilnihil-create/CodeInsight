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
    ll N;
    cin >> N;
    vector<string> s(N);
    unordered_map<string, ll> m;
    rep(i, N) {
        cin >> s[i];
        SORT(s[i]);
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
        } else {
            m[s[i]] += 1;
        }
    }

    ll ans = 0;
    for (auto x : m) {
        ans += x.second * (x.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
