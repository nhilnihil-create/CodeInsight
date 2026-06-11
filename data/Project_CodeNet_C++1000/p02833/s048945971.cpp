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
 
//const long long INF = 1e18 ;
//const long long NINF = -1e17 ;

int main(){
    FAST_IO ;
    bigint N ; cin >> N ;
    if( N % 2 != 0 ){
        cout << "0" << endl ;
        return 0 ;
    }
    bigint ans = 0 ;
    ans += N / 10 ;
    N /= 10 ;
    while( N ){
        ans = ans + (N / 5) ;
        N /= 5 ;
    }
    cout << ans << endl ;
    return 0 ;
}
 