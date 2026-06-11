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
    ll K;
    cin >> K;
    queue<ll> q;
    rep(i, 9) { q.push(i + 1); }

    ll ans = 0;
    rep(i, K) {
        ll tmp = q.front();
        q.pop();
        if (tmp % 10 != 0) {
            q.push(tmp * 10 + tmp % 10 - 1);
        }
        q.push(tmp * 10 + tmp % 10);
        if (tmp % 10 != 9) {
            q.push(tmp * 10 + tmp % 10 + 1);
        }
        ans = tmp;
    }

    cout << ans << endl;

    return 0;
}
