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
    int k, n;
    cin >> k >> n;
    int a[n];
    rep(i, n) {
        cin >> a[i];
    }
    // solve
    int d = 0;
    rep(i, n) {
        if (i != n-1) chmax(d, a[i+1]-a[i]);
        else chmax(d, a[0]+(k-a[i]));
    }
    // output
    cout << k-d << endl;
}