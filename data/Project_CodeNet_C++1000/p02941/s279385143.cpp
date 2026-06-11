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
    int n;
    cin >> n;
    vl a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < n; ++i) {
        pq.emplace(b[i], i);
    }
    ll ret = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        ll val  = p.first;
        int idx = p.second;
        int l   = idx == 0 ? n - 1 : idx - 1;
        int r   = idx == n - 1 ? 0 : idx + 1;
        ll op   = (val - a[idx]) / (b[l] + b[r]);
        val -= op * (b[l] + b[r]);
        b[idx] -= op * (b[l] + b[r]);
        ret += op;
        if (val != a[idx]) {
            if (op == 0) {
                cout << -1 << "\n";
                return 0;
            }
            pq.emplace(val, idx);
        }
    }
    cout << ret << "\n";
    return 0;
}