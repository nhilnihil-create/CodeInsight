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

const int K = 5555;
int od[K], d[K];
int k, q, n, x, m;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> q;
    rep(i, 0, k - 1) {
        cin >> od[i];
    }
    while(q--) {
        cin >> n >> x >> m;
        rep(i, 0, k - 1) {
            d[i] = od[i] % m;
        }
        int a = x;
        rep(j, 0, k - 1) {
            a += (n - 1) / k * d[j];
            if((n - 1) % k > j) {
                a += d[j];
            }
        }
        int b = 0;
        rep(j, 0, k - 1) {
            if(d[j]) continue;
            b += (n - 1) / k;
            if((n - 1) % k > j) {
                b++;
            }
        }
        int ans = n - 1 - (a / m - x / m) - b;
        cout << ans << endl;
    }
    return 0;
}
