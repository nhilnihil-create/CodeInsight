#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

int pow2[13];

signed main() {
    pow2[0] = 1;
    rep(i, 12) pow2[i+1] = pow2[i] * 2;
    
    int n, m;
    cin >> n >> m;
    
    vector<int> keys(pow2[n], INT_MAX);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        int k = 0;
        rep(j,b){
            int c; cin >> c;
            k += pow2[c-1];
        }
        keys[k] = min(keys[k], a);
    }
    
    rep(_,n){
        rep(i,pow2[n])reps(j,i+1,pow2[n]-1){
            int merged = i | j;
            keys[merged] = min(keys[merged], keys[i] + keys[j]);
        }
    }
    
    if(keys[pow2[n]-1] == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << keys[pow2[n]-1] << endl;
    }
}