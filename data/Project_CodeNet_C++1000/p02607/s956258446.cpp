#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    ll ans = 0;
    rep(i, 0, n) {
        if(a[i] % 2 == 1 && i % 2 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}