#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/dsu>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n,t; cin >> n >> t;
    vector<pair<int,int>> f(n);
    rep(i,n) {
        int a,b; cin >> a >> b;
        f[i] = {a,b};
    }
    sort(all(f));

    int dp[6005]; rep(j,6005) dp[j] = 0;
    rep(i,n) {
        int a = f[i].first;
        int b = f[i].second;
        for(int j = t-1; j >= 0; j--) {
            dp[j+a] = max(dp[j+a], dp[j]+b);
        }
    }
    int ans = 0;
    rep(j,6005) ans = max(ans, dp[j]);
    cout << ans << endl;
    return 0;
}
