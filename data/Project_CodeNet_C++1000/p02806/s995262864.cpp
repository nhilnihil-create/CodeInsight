#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<string> s(n);
    vector<ll> t(n);
    rep(i, 0, n) cin >> s[i] >> t[i];
    string x;
    cin >> x;
    ll ans = 0;
    bool f = false;
    rep(i, 0, n) {
        if(f) ans += t[i];
        if(s[i] == x) f = true;
    }
    cout << ans << endl;
    return 0;
}