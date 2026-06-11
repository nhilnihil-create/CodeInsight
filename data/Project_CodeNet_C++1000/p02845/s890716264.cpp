#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //ansを出力する時は (ans % mod + mod) % mod とする(負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976


int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];
    ll left[n],use[n];
    rep(i,n){
        left[i] = 3;
        use[i] = 0;
    }
    ll ans = 1;
    rep(i,n){
        if(a[i] == 0){
            ans *= left[a[i]];
            left[0]--;
        }else{
            ans *= min(left[a[i]],left[a[i]] - left[a[i]-1]);
            left[a[i]]--;
        }
        
        ans %= mod;
    }
    cout << ans % mod << endl;
}