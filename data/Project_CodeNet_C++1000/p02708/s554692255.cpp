#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;
int main(){
    FAST_IO ;
    bigint N , K ; cin >> N >> K ;
    bigint max_sum = (N * ( N + 1 )) / 2 ;
    bigint min_sum[N+3] ;
    memset(min_sum, 0, sizeof(min_sum)) ;
    min_sum[1] = 0 ;
    for( int i = 2 ; i <= N + 1 ; i++ ){
        min_sum[i] = min_sum[i-1] + i - 1 ;
    }
    bigint ans = 0 ;
    for( bigint i = K ; i <= N + 1; i++ ){
        bigint a = ((max_sum - min_sum[N-i+1] - min_sum[i] + 1) % mod + mod ) % mod ;
        ans = ( ans + a ) % mod ;
    }
    cout << ans << endl ;
    
    return 0 ;
}
 
 