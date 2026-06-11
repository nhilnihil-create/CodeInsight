#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    string L;

    cin >> L;
    reverse(L.begin(), L.end());

    ll dp[100100][2] = {0};
    dp[L.size()-1][0] = 1;
    dp[L.size()-1][1] = 2;
    for( int i = L.size()-2; i >= 0 ; i-- ){
        dp[i][0] = (dp[i+1][0]*3)%MOD;
        if( L[i] == '0' ){
            dp[i][1] = (dp[i+1][1])%MOD;
        }else{
            dp[i][0] += (dp[i+1][1])%MOD;
            dp[i][1] = (dp[i+1][1]*2)%MOD;
        }
    }

    cout << (dp[0][0]+dp[0][1])%MOD << endl;
}
