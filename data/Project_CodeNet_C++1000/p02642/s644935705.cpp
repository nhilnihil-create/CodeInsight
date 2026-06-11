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
    vector<ll> A(N);
    unordered_map<ll, ll> A_cnt_m;
    ll A_max = 0;
    rep(i, N) {
        cin >> A[i];
        if (A_cnt_m.find(A[i]) == A_cnt_m.end()) {
            A_cnt_m[A[i]] = 1;
        } else {
            A_cnt_m[A[i]] += 1;
        }
        A_max = max(A_max, A[i]);
    }
    vector<bool> dp(A_max, true);
    SORT(A);
    set<ll> A_set(A.begin(), A.end());
    for (auto a : A_set) {
        ll i = a + a;
        while (i <= A_max) {
            dp[i - 1] = false;
            i += a;
        }
    }

    ll ans = 0;
    for (auto a : A) {
        if (A_cnt_m[a] == 1) {
            ans += dp[a - 1];
        }
    }
    cout << ans << endl;

    return 0;
}
