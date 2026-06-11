#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

int main() {
    string L;
    cin >> L;
    int n = L.size();
    vector<ll> dp0(n + 1, 0), dp1(n + 1, 0);
    dp1[0] = 1;
    ll MOD = 1e9 + 7;
    rep(i, n) {
        if (L[i] == '0') {
            dp1[i + 1] = dp1[i]; 
            dp0[i + 1] = (dp0[i] * 3) % MOD;
        } else {
            dp1[i + 1] = (dp1[i] * 2) % MOD;
            dp0[i + 1] = (dp0[i] * 3 + dp1[i]) % MOD;
        }
    }
    cout << (dp0[n] + dp1[n]) % MOD << "\n";
}