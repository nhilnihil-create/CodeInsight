#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int s;
long long dp[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> s;
    dp[0] = 1;
    for (int j = 1; j <= s; j++) {
        for (int i = 3; i <= s; i++) {
            if (j >= i) dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    cout << dp[s] << '\n';

    return 0;
}
