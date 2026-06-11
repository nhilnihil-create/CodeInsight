#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    const ll mod = 1000000000 + 7;
    vector<ll> dp1(n+10, 0), dp2(n+10, 0);
    dp1[0] = 1;
    rep(i, 0, n) {
        // smaller => smaller
        dp2[i+1] += 3 * dp2[i];
        // exact => smaller
        if(s[i] == '1') dp2[i+1] += dp1[i];
        // exact => exact
        if(s[i] == '1') dp1[i+1] += 2 * dp1[i]; 
        else dp1[i+1] += dp1[i];
        dp1[i+1] %= mod;
        dp2[i+1] %= mod;
    }
    cout << (dp1[n] + dp2[n]) % mod << endl;
    return 0;
}