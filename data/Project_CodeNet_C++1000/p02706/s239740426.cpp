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
    int N , M ; cin >> N >> M ;
    int  sum = 0 ;
    for( int i = 0 ; i < M ; i++ ){
        int x ; cin >> x ;
        sum += x ;
    }
    cout << max( -1 , N - sum ) << endl ;
    
    return 0 ;
}
 
 