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

int dp[5010][5010];

int main(){
    int n;
    string s;
    cin >> n >> s;

    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j >= i; --j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (dp[i][j] <= j - i) chmax(res, dp[i][j]);
        }
    }
    cout << res << endl;
}