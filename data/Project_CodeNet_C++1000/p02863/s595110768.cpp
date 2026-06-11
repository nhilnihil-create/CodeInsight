#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;
 
int main() {
    fastIO
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<P> a(n);
    rep(i, n) {
        cin >> a[i].first >> a[i].second;
    }
 
    sort(all(a));
 
    vi dp(t, -1);
    dp[0] = 0;
    int ans = 0;
    rep(i, n) {
        for(int j = t-1; j >= 0; --j) {
            if(dp[j] != -1) {
                if(j+a[i].first < t) {
                    dp[j+a[i].first] = max(dp[j+a[i].first], dp[j]+a[i].second);
                } else {
                    ans = max(ans, dp[j]+a[i].second);
                }
            }
        } 
    }
 
    rep(i, t) {
        ans = max(ans, dp[i]);
    }
 
    cout << ans << endl;
}