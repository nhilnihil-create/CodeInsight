#include<bits/stdc++.h>
using namespace std;

#define LL long long
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    LL n, m; cin >> n >> m; int a[m];
    map<int, int> mp;
    for(int &i : a) cin >> i, mp[i]++;
    LL dp[n+1]={};

    dp[0] = 1LL; dp[1] = !(mp[1]);
    for(int i = 2; i <= n; i++) {
        if(mp[i]) continue;
        (dp[i] += dp[i-1] + dp[i-2]) %= mod;
    }    
    cout << dp[n];
}