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

int dp[1000010][2];

int main(){
    string n;
    cin >> n;

    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 0; i < n.size(); ++i) {
        dp[i+1][0] = min(dp[i][0] + (n[i] - '0'), dp[i][1] + 10 - (n[i] - '0'));
        dp[i+1][1] = min(dp[i][0] + (n[i] - '0') + 1, dp[i][1] + 9 - (n[i] - '0'));
    }
    cout << dp[n.size()][0] << endl;
}
