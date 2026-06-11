//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int w, h;
    cin >> h >> w;
    int a, b;
    cin >> a >> b;

    vvi s(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            s[i][j] = 0;
        }
    }


    rep(i, h) {
        rep(j, a) {
            s[i][j] = 1;
        }
    }

    rep(i, b) {
        rep(j, w) {
            s[i][j] ^= 1;
        }
    }


    rep(i, h) {
        rep(j, w) {
            cout << s[i][j];
        }
        cout << endl;
    }
}