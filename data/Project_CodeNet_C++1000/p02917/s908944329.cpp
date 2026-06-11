#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> b(n-1);
    rep(i, 0, n-1) cin >> b[i];
    ll ans = b[0] + b[n-2];
    rep(i, 0, n-2){
        ans += min(b[i], b[i+1]);
    }
    cout << ans << endl;
    return 0;
}