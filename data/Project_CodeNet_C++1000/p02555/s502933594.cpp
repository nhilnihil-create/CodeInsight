#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

ll dp[2010][710];
ll mod = 1e9+7;

int main(){
    rep(i,2010){
        rep(j,710){
            dp[i][j] = 0;
        }
    }
    dp[3][1] = 1;


    int s;
    cin >> s;
    reps(i,4,2010){
        rep(j,701){
            dp[i][j] = dp[i-1][j];
            if(i-3>=0 && j>=1)  dp[i][j] = (dp[i][j] + dp[i-3][j-1]) % mod;
        }
    }

    
    ll ans = 0;
    rep(i,700){
        ans = (ans + dp[s][i] ) % mod; 
    }
    
    cout << ans << endl;
    return 0;
}