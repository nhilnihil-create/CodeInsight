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
bigint arr[300011] ;
int main(){
    int N ; cin >> N ;
    for( int i = 0 ; i < N ; i++ )
        cin >> arr[i] ;
    bigint ans = 0 ;
    bigint two = 1 ;
    for( bigint i = 0 ; i < 61 ; i++ ){
        bigint set = 0 , K = ( 1LL << i ) ;
        for( int j = 0 ; j < N ; j++ ){
           if( arr[j] & K )
               set++ ;
        }
        bigint A = set * ( N - set ) % mod ;
        ans += A * two ;
        ans %= mod ;
        two = two * 2 % mod  ;
    }
    cout << ans << endl ;
    return 0 ;
}
