#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i <= n; i += i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i -= i&-i) {
            x += d[i];
        }
        return x;
    }
    T semiopenSum(int l, int r) {
        // [l,r)の半開区間
        return sum(r-1) - sum(l-1);
    }
};  // BIT<int> bit(N);

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    BIT<ll> bit(N);
    rep(i, N) bit.add(i, A[i]);
    rep(i, Q) {
        int q, a, b;
        cin >> q >> a >> b;
        if (q == 0) {
            bit.add(a, b);
        } else {
            ll sum = bit.semiopenSum(a, b);
            cout << sum << '\n';
        }
    }
    return 0;
    // ll, 0, -, 1i, for s&g, debug
}