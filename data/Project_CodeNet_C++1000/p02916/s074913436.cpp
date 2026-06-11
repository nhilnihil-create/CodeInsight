#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+1), b(n+1), c(n+1);
    rep(i, 1, n+1) cin >> a[i];
    rep(i, 1, n+1) cin >> b[i];
    rep(i, 1, n) cin >> c[i];
    ll ans = 0;
    rep(i, 1, n+1){
        //cerr << b[a[i]] << endl;
        ans += b[a[i]];
        if(i+1 <= n && a[i+1] == a[i] + 1) ans += c[a[i]]; 
    }
    cout << ans << endl;
    return 0;
}