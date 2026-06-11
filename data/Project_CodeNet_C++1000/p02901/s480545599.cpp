#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int dp[1010][(1<<12) + 10];

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<int> c(m, 0);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 0; j < b[i]; ++j) {
            int c_;
            cin >> c_;
            c_--;
            c[i] |= (1<<c_);
        }
    }

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j < (1<<n); ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1<<n); ++j) {
            chmin(dp[i+1][j], dp[i][j]);
            chmin(dp[i+1][j|c[i]], dp[i][j] + a[i]);
        }
    }
    int res = dp[m][(1<<n) - 1];
    cout << (res == INF ? -1 : res) << endl;
}