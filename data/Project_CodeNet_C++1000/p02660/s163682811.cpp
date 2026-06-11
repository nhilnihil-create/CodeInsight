#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    ll N;
    cin >> N;
    set<ll> exist;
    map<ll, ll> counter;
    for (ll i = 2, end = sqrt(N); i < end; ++i) {
        while (N % i == 0) {
            N /= i;
            if (exist.find(i) == exist.end()) {
                exist.emplace(i);
                counter.emplace(i, 1);
            } else {
                ++counter[i];
            }
        }
    }

    if (N != 1) counter.emplace(N, 1);

    ll ans = 0;
    for (auto x : counter) {
        ll cnt = x.second;
        for (int i = 2;; ++i) {
            if (i * (i + 1) / 2 > cnt) {
                ans += i - 1;
                break;
            }
        }
    }
    cout << ans << endl;
}