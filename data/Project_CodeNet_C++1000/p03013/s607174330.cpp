#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int main() {
    int n,m,a; cin >> n >> m ;
    vector<int> dp(1000000);
    bool flag = false;

    dp[0] = 1;
    dp[1] = 1;

    rep(i,m){
        cin >> a;
        dp[a] = -1;
    }

    if(dp[1] == -1) dp[1] = 0;

    for(int i = 2; i <= n; i ++){

        if(dp[i] == -1){
            dp[i] = 0;
        }else{
            dp[i] = dp[i-1] + dp[i-2];
        }
        dp[i] %= 1000000007;
    }

    cout << dp[n];

    return 0;
}
