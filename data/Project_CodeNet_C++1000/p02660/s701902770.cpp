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

map<bigint , int> m ;
int count1( int N ){
    return int((-1 + sqrt(1 + 8 * N)) / 2);
}
void factorize(bigint N ){
    for( bigint i = 2 ; i * i <= N ; i++ ){
        while( N % i == 0 ){
            m[i]++ ;
            N /= i ;
        }
    }
    if( N > 1 )
        m[N]++ ;
}
int main(){
    bigint N ; cin >> N ;
    factorize(N) ;
    int ans = 0 ;
    for( auto x : m ){
        ans += ( count1(x.second)) ;
    }
    cout << ans << endl ;
    return 0 ;
}

