#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

vector<ll> dp(2001,0);

void pre(){
    dp[3] = 1;
    for(int i=4; i<2001; i++){
        for(int j=0; j<=i-3; j++){
            dp[i] += dp[j];
        }
        dp[i]++;
        dp[i] %= MOD;
    }
}

int main(){
    pre();
    int s;  cin >> s;
    print(dp[s]);
}