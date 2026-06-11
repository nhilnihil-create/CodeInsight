#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, k;
    cin >> n >> k;
    const ll mod = 1000000007;
    ll mn = 0, mx = 0;
    rep(i, 0, k) mn += i;
    rep(i, 0, k) mx += n-i;  
    ll ans = 0;
    rep(i, k, n+2){
        //cerr << mn << " " << mx << endl;
        ans += mx - mn + 1;
        ans %= mod;
        mn += i;
        mx += n-i;
        mn %= mod;
        mx %= mod;
    }
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}