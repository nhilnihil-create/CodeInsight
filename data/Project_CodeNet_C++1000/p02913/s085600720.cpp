#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define ve vector
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

int main(){
    int n;
    string s;
    cin >> n >> s;
    ve<ve<int>> dp(n,ve<int>(n,0));
    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(s[i] != s[j]) continue;
            else{
                dp[i][j]++;
                if(i+1<n && j+1<n)dp[i][j] += dp[i+1][j+1];
            }
        }
    }
    int ans = 0;
    rep(i,n)rep(j,n){
        ans = max(ans, min(dp[i][j], (int)(j-i)));
    }
    cout << ans << endl;
    return 0;
}