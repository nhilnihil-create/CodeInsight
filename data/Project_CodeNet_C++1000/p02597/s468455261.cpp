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
    int N ; cin >> N ;
    string str ; cin >> str ;
    int cnt = 0 ;
    for( int i = 0 ; i < N ; i++ ){
        if( str[i] == 'R' )
            cnt++ ;
    }
    int ans = 0 ;
    for( int i = 0 ; i < cnt ; i++ ){
        if( str[i] == 'W' )
            ans++ ;
    }
    cout << ans << endl ;
    return 0 ;
}
 
 