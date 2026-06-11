#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    map<P, int> mp;
    int mx;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            int dx = x[j] - x[i], dy = y[j] - y[i];
            chmax(mx, ++mp[P(dx, dy)]);
        }
    }
    cout << n - mx << endl;
}