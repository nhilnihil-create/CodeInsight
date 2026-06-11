#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
    ll S;
    cin >> S; 

    ll dp[S+10];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;

    for(ll i = 6; i <= S; i++){
        dp[i] = (dp[i - 1]%MOD + dp[i - 3]%MOD)%MOD;
    }

    cout << dp[S] << endl;

    return 0;
}