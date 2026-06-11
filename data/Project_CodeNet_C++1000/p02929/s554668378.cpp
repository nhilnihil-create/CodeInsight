#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define se second
#define fi first
#define prev            :oyhhhhhhyo:    
#define next         .sdNNNmNNNNNNNmds. 
#define y0          -hNNNNy`yNNNNNN`/Nh-
#define y1          mNNNNNd+dNNNNNN+sNNm
#define yn          mNNNNNNNNy--:smNNNms
#define tm          .+oooooosyysooooo+- 
#define read               :yhy/        
#define rank              :mNmo         
#define index              ... 
#define pb push_back
#define pcnt __builtin_popcountll
#define rrep(i,a,b) for(int i = (b); i >= (a); i--)
#define rall(x,a) for(auto x : a)
#define MOD 1000000007
#define endl "\n"
#define int long long
typedef long long ll;
using namespace std;

const int N = 111111;
int fact[N];
string s;
int n;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    fact[0] = 1;
    rep(i, 1, n) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    int op = 0, ans = 1;
    rep(i, 1, 2 * n) {
        if((s[i - 1] == 'B') ^ (op & 1)) {
            op++;
        } else {
            ans = ans * op % MOD;
            op--;
        }
        if(op < 0) {
            ans = 0;
            break;
        }
    }
    if(op) {
        ans = 0;
    }
    ans = ans * fact[n] % MOD;
    cout << ans << endl;
    return 0;
}
