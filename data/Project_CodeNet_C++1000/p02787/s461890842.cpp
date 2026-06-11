#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,n;
    cin >> h >> n;

    vector<int> a(n);
    vector<int> b(n);
    int mx=0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        mx=max(mx,a[i]);
    }

    vector<int> dp(h+mx,1e9);
    dp[0]=0;

    for(int i = 1; i < h+mx; i++) {
        for(int j = 0; j < n; j++) {
            if(a[j]<=i) dp[i] = min(dp[i],dp[i-a[j]]+b[j]);
        }
    }
    int ans=dp[h];
    for(int i = 0; i < mx; i++) {
        ans=min(ans,dp[h+i]);
    }
    cout << ans << "\n";

    return 0;
}