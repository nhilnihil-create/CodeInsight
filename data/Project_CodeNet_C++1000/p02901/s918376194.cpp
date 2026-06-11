#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n, m;
    cin >> n >> m;
    vector<P> key;
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        int s = 0;
        rep(j,b) {
            int c;
            cin >> c;
            c--;
            s |= 1<<c;
        }
        key.emplace_back(s,a);
    }

    vector<int> dp(1<<n, INF);
    dp[0] = 0;
    rep(s,1<<n) {
        rep(i,m) {
            int t = s | key[i].first;
            chmin(dp[t], dp[s] + key[i].second);
        }
    }
    int ans = dp.back();
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}