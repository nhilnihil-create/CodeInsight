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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<pair<ll, char>> apple;
    apple.reserve(A + B + C);
    rep(i, A) {
        ll num;
        cin >> num;
        apple.emplace_back(num, 'r');
    }
    rep(i, B) {
        ll num;
        cin >> num;
        apple.emplace_back(num, 'g');
    }
    rep(i, C) {
        ll num;
        cin >> num;
        apple.emplace_back(num, 'l');
    }

    sort(all(apple), greater<pair<ll, char>>());

    ll cnt_r = 0;
    ll cnt_g = 0;
    ll cnt_l = 0;
    ll ans = 0;
    for (auto e : apple) {
        if (e.second == 'l') {
            ans += e.first;
            ++cnt_l;
        } else if (e.second == 'r') {
            if (cnt_r >= X) continue;
            ans += e.first;
            ++cnt_r;
        } else if (e.second == 'g') {
            if (cnt_g >= Y) continue;
            ans += e.first;
            ++cnt_g;
        }

        if (cnt_r + cnt_g + cnt_l == X + Y) {
            break;
        }
    }

    cout << ans << endl;
}