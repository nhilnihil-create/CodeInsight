#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    ll n;
    cin >> n;
    map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        cnt[a]++;
    }
    vector<ll> as(n + 1, 0);
    for (auto &p : cnt) {
        as[p.second]++;
    }
    for (int i = n - 1; i >= 0; --i) {
        as[i] += as[i + 1];
    }
    vector<ll> ret(n, 0);
    for (int i = as[1] - 1; i >= 0; --i) {
        ll temp = 0;
        while (as[ret[i] + 1] == i + 1) {
            ret[i]++;
            as[ret[i]]--;
            temp++;
        }
        for (int j = 1; j <= n; ++j) {
            ll add = min(temp, as[1] - as[j]);
            as[j] += add;
            temp -= add;
            if (temp == 0)
                break;
        }
    }
    for (auto &r : ret) {
        cout << r << "\n";
    }
    return 0;
}