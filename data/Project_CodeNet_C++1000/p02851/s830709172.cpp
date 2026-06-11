#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d(ll x){
    ll ans = 0;
    while(x){
        ++ans;
        x/=10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll dp[n+1];
    dp[0]=0;
    for(int i=1; i<=n; i++){
        cin >> dp[i];
        --dp[i];
        dp[i]+=dp[i-1];
        dp[i]%=k;
    }
    ll ans = 0;
    map<int, int> mp;mp[0]=1;
    for(int i=1; i<=n;i++){
        if(i>=k) mp[dp[i-k]]--;
        ans+= mp[dp[i]]++;
    }
    cout << ans;
    return 0;
}
