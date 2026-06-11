#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
#define F first
#define S second

const int mxn = 2e5+5, MOD = 1e9+7;
int n, k;
int pref[mxn], suf[mxn];

void solve(){
    cin >> n >> k;
    
    pref[0] = 1;
    for(int i = 1; i <= n; ++i) pref[i] = (pref[i-1] + i+1) % MOD;

    suf[n] = n+1;
    for(int i = n-1; i >= 0; --i) suf[i] = (suf[i+1] + i+1) % MOD;

    int ans = 0;
    for(int i = k; i <= n+1; ++i){
        int add = ((suf[n-i+1] - pref[i-1] + 1) % MOD + MOD) % MOD;
        ans = (ans + add) % MOD;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}