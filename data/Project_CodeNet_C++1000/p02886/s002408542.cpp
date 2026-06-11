#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> d(n);
    rep(i, 0, n) cin >> d[i];
    ll ans = 0;
    rep(i, 0, n-1){
        rep(j, i+1, n) ans += d[i] * d[j];
    }
    cout << ans << endl;
    return 0;
}