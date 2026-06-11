#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    // input
    int n;
    cin >> n;
    int x[n];
    rep(i, n) {
        cin >> x[i];
    }
    // solve
    ll min_p = INF;
    for (int p = 1; p <= 100; p++) {
        ll sum = 0;
        rep(i, n) {
            sum += (x[i]-p)*(x[i]-p);
        }
        chmin(min_p, sum);
    }
    // output
    cout << min_p << endl;
}