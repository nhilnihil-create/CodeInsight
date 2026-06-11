#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

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
    int n, k;
    cin >> n >> k;
    int p[n];
    double e[n];
    rep(i, n) {
        cin >> p[i];
        e[i] = (p[i] + 1) / 2.0;
    }
    // solve
    double s[n+1];
    rep(i, n+1) {
        if (i == 0) s[i] = 0.0;
        else s[i] = s[i-1] + e[i-1];
    }
    double max_e = 0.0;
    rep(i, n-k+1) {
        chmax(max_e, s[i+k]-s[i]);
    }
    // output
    cout << fixed << setprecision(10) << max_e << endl;
}