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
//#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

const int N = 1111111;
int a[N];
int n;

bool isodd(vector<bool>& v) {
    bool ans = v[0];
    int n2 = 0;
    int m = 1;
    rep(j, 2, n) {
        m = m * (n - j + 1) / (j - 1);
        int num = n - j + 1;
        while(num % 2 == 0) {
            n2++;
            num >>= 1;
        }
        int den = j - 1;
        while(den % 2 == 0) {
            n2--;
            den >>= 1;
        }
        if(!n2) {
            ans ^= v[j - 1];
        }
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> n >> s;
    rep(i, 1, n) {
        a[i] = s[i - 1] - '0' - 1;
    }
    vector<bool> v;
    rep(i, 1, n) {
        v.pb(a[i] & 1);
    }
    if(isodd(v)) {
        cout << 1 << endl;
    } else {
        bool has1 = false;
        rep(i, 1, n) {
            has1 |= a[i] == 1;
        }
        if(has1) {
            cout << 0 << endl;
        } else {
            v.clear();
            rep(i, 1, n) {
                v.pb(a[i] / 2);
            }
            int ans = isodd(v) ? 2 : 0;
            cout << ans << endl;
        }
    }
    return 0;
}
