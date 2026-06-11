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

const int N = 111;
int mat[N][N];
int n, k;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int cur = (n - 1) * (n - 2) / 2;
    if(cur < k) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, 2, n) {
        mat[1][i] = 1;
        mat[i][1] = 1;
    }
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if(!mat[i][j] && cur > k) {
                cur--;
                mat[i][j] = 1;
                mat[j][i] = 1;
            }
        }
    }
    vector<pair<int, int> > ans;
    rep(i, 1, n) {
        rep(j, i + 1, n) {
            if(mat[i][j]) {
                ans.pb({i, j});
            }
        }
    }
    cout << sz(ans) << endl;
    rall(p, ans) {
        cout << p.fi << " " << p.se << endl;
    }
    return 0;
}
