//According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible.
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;
bigint dp[300011] ;
int main(){
    FAST_IO ;
    dp[0] = 1 ;
    dp[1] = 1 ;
    bigint N , M ; cin >> N >> M ;
    for( int i = 0 ; i < M ; i++ ){
        int x ; cin >> x ;
        dp[x] = -1 ;
    }
    for( int i = 2 ; i <= N ; i++ ){
        if( dp[i] == -1 ){
            continue ;
        }
        if( dp[i-1] != -1 )
            dp[i] += dp[i-1] % mod ;
        if( dp[i-2] != -1 )
            dp[i] += dp[i-2] % mod ;
    }
    if( dp[N] != -1 )
        cout << dp[N] % mod << endl ;
    else
        cout << "0" << endl ;
    return 0 ;
}
