#include <bits/stdc++.h>
#define rrep(i, n) for(int i = int(n-1); i >= 0; i--)

using namespace std;

long dp[3001];

int main(){
    int n, s; cin >> n >> s;
    dp[0] = 1;
    rrep(i,n){
        int a; cin >> a;
        rrep(j,s+1){
            dp[j] *= 2;
            if(j-a >= 0) dp[j] += dp[j-a];
            dp[j] %= 998244353;
        }
    }
    cout << dp[s] << endl;
}