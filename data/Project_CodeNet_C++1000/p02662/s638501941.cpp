#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;
const ll mod = 998244353;


ll dp[3010][3010];

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3010; ++j) {
            dp[i+1][j] += 2 * dp[i][j];
            dp[i+1][j] %= mod;
            if (j - a[i] >= 0){
                dp[i+1][j] += dp[i][j-a[i]];
                dp[i+1][j] %= mod;
            }
        }
    }
    cout << dp[n][s] << endl;
}
