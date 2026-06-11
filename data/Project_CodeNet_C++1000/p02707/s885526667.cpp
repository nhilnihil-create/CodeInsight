#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 10000007
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;




int main(){
    FAST_IO ;
    int N ; cin >> N ;
    int cnt[N+2] ;
    memset(cnt, 0, sizeof(cnt)) ;
    for( int i = 0 ; i < N - 1 ; i++ ){
        int x ; cin >> x ;
        cnt[x]++ ;
    }
    
    for( int i = 1 ; i <= N ; i++ )
        cout << cnt[i] << endl ;
    return 0 ;
}
 
 