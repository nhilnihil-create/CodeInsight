#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define ina(n,a) cin >> n; for(int i = 1; i <= n; i++) cin >> a[i]
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            coyhhhhhhyoc    
#define next          sdNNNmNNNNNNNmds  
#define y0           hNNNNy_yNNNNNN_sNh
#define y1          mNNNNNdtdNNNNNNtsNNm
#define yn          mNNNNNNNNy___smNNNms
#define tm            oooooosyysooooot 
#define read               tyhyt        
#define rank              ytmNmo         
#define index              yyy
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 3333;
pair<int, int> ab[N];
int dp[N][N][2];
int n, t;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> t;
    rep(i, 1, n) {
        cin >> ab[i].fi >> ab[i].se;
    }
    sort(ab + 1, ab + n + 1);
    rep(i, 1, n) {
        rep(ct, 0, t) {
            int pt = ct - ab[i].fi;
            dp[i][ct][0] = max(dp[i - 1][ct][0], dp[i - 1][ct][1]);
            if(pt >= 0) {
                dp[i][ct][1] = max(dp[i - 1][pt][0], dp[i - 1][pt][1]) + ab[i].se;
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        rep(ct, 0, t - 1) {
            ans = max(ans, dp[i][ct][1]);
            ans = max(ans, dp[i][ct][0] + ab[i].se);
        }
    }
    cout << ans << endl;
    return 0;
}
