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

const int N = 222222;
int a[N], s[N], t[N];
int n, k;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        t[i] = ((s[i] - i) % k + k) % k;
    }
    map<int, int> cnt;
    int ans = 0;
    cnt[0]++;
    rep(i, 1, n) {
        if(i - k >= 0) {
            cnt[t[i - k]]--;
        }
        ans += cnt[t[i]];
        cnt[t[i]]++;
    }
    cout << ans << endl;
    return 0;
}
