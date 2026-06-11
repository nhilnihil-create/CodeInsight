#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
long long inf = pow(10, 9);

int n, a[81];
long long dp[81];
int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    dp[0] = 1000;
    rep(i, n){
        rep(j, i){
            dp[i] = max(dp[i], dp[j]);
            dp[i] = max(dp[i], (dp[j] / a[j]) * a[i] + dp[j] % a[j]);
        }
    }
    cout << dp[n - 1] << endl;
}