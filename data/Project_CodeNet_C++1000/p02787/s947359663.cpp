//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
#define V vector
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

const int INF = 1e9;

int main () {
    int h, n; cin >> h >> n;
    V<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    V<int> dp(h+1, INF);//dp[i]:体力をi減らすのに必要な魔力のmin
    dp[0] = 0;
    rep(i, n) {
        for (int j = 0; j <= h; j++) {
            int nj = min(h, j + a[i]);
            chmin(dp[nj], dp[j] + b[i]);
        }
    }
    cout << dp[h] << endl;
    return 0;
}