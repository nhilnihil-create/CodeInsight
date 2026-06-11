#include <bits/stdc++.h>

using namespace std;

#define Fast  ios::sync_with_stdio(false); cin.tie(0)
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define mp make_pair
#define S second
#define F first
typedef long long ll;
const int mod = 1e9 + 7;
const ll N = 1e6 + 5;
ll inf = 1e18;

ll dp[N];

int main(){

    Fast;

    ll n;
    cin >> n;

    dp[3] = 1;
    for(int i = 4; i <= n; i ++){
         dp[i] = 1;
        for(int j = 1; j <= i-3; j ++){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout << dp[n];

    return 0;
}
