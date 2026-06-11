#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 998244353;
const int N = 1e6+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,s;
    cin>>n>>s;
    int dp[n+1][s+1];
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    dp[0][0]=1;
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=s;j++) {
            dp[i+1][j]+=2*dp[i][j];
            dp[i+1][j]%=MOD;
            if(j+arr[i]<=s) {
                dp[i+1][j+arr[i]]+=dp[i][j];
                dp[i+1][j+arr[i]]%=MOD;
            }
        }
    }
    cout<<dp[n][s];

    return 0;
}