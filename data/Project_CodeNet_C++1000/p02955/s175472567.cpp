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

// list up all factors
template <typename T>
set<T> factors(T a) {
    set<T> facs;
    for (T i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            facs.insert(i);
            facs.insert(a / i);
        }
    }
    return facs;
}

int main() {
    int n, k;
    cin >> n >> k;
    vl a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    auto facs = factors(sum);
    ll ret    = 1;
    for (auto &f : facs) {
        if (f == 1)
            continue;
        vl b   = a;
        ll sum = 0;
        for (auto &x : b) {
            x %= f;
            sum += x;
        }
        sort(b.begin(), b.end());
        ll step = 0;
        for (int i = 0; i < n - (sum / f); ++i) {
            step += b[i];
        }
        if (step <= k)
            chmax(ret, f);
    }
    cout << ret << "\n";
    return 0;
}