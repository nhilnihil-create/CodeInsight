//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    vvi x(h, vi(w));
    rep(i, h) {
        rep(j, a) {
            x[i][j] ^= 1;
        }
    }
    rep(i, b) {
        rep(j, w) {
            x[i][j] ^= 1;
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << x[i][j];
        } cout << '\n';
    }
}