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

int dp[1010][20010];

int main(){
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < 1010; ++i) {
        for (int j = 0; j < 20010; ++j) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 20010; ++j) {
            dp[i+1][j] = dp[i][j];
            if (j - a[i] >= 0){
                chmin(dp[i+1][j], dp[i+1][j-a[i]] + b[i]);
            }
        }
    }

    int res = INF;
    for (int i = h; i < 20010; ++i) {
        chmin(res, dp[n][i]);
    }
    cout << res << endl;
}