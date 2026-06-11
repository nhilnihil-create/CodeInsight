#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

static const int INF = 1001001001;
static const int MAX = 2005;
ll dp[MAX][MAX];

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i, n+1) rep(j, n+1) dp[i][j] = -INF;
    dp[0][0] = 0;
    vector<P> p;
    rep(i,n) p.emplace_back(a[i],i);
    sort(p.rbegin(), p.rend());
    rep(i,n){
        int pi = p[i].second;
        rep(l,i+1) {
            int r = i - l;
            dp[i+1][l+1] = max(dp[i+1][l+1] , dp[i][l]+ll(pi-l)*a[pi]);
            dp[i+1][l] = max(dp[i+1][l], dp[i][l]+ll((n-r-1)-pi)*a[pi]); 
        }
    }
    ll ans = 0;
    rep(i,n+1) ans = max(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}