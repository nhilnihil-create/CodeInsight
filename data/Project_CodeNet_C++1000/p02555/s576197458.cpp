#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007

int main (){
    int s ;
    cin >> s ;
    vector<ll> dp (s + 1) ;
    dp[0] = 1 ;
    rep(i, s + 1){
        if(i - 3 < 0) continue ;
        else {
            for(int j = i - 3 ; j >= 0 ; j--){
                dp[i] += dp[j] ;
                dp[i] %= mod ;
            }
        }
    }
    cout << dp[s] << endl ; 
}