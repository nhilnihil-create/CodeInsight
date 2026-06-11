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
#define int long long
typedef long long ll;
using namespace std;

const int N = 2222;
int dp[N][N], sum[N][N];
int a[N], b[N];
int n, m;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> a[i];
    }
    rep(j, 1, m) {
        cin >> b[j];
    }
    dp[0][0] = 1;
    sum[0][0] = 1;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(i && j) {
                if(a[i] == b[j]) {
                    dp[i][j] = sum[i - 1][j - 1];
                }
                sum[i][j] = dp[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            } else if(j > 0) {
                sum[0][j] = sum[0][j - 1];
            } else if(i > 0) {
                sum[i][0] = sum[i - 1][0];
            }
            sum[i][j] = (sum[i][j] % MOD + MOD) % MOD;
        }
    }
    cout << sum[n][m] << endl;
    return 0;
}
