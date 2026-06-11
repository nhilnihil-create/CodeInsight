#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    ll dp[n+1];
    dp[0] = 0;
    for(int i=0; i<n; i++)
        dp[i+1] = (dp[i] + a[i] -1) % k;
    map<int, int> mp;
    ll ans = 0;
    mp[0] = 1;
    for(int i=1; i<=n; i++){
        if(i>=k) mp[dp[i-k]]--;
        ans += mp[dp[i]]++;
    }
    cout << ans << endl;
    return 0;
}
