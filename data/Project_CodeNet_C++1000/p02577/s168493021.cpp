#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 100000
#define endl "\n"
#define PI 3.14159265358979323846264338327950288
 
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;


int main(){
    FAST_IO ;
    string str ; cin >> str ;
    int N = ( int ) str.length() ;
    int sum = 0 ;
    for( int i = 0 ; i < N ; i++ ){
        int d = str[i] - '0' ;
        ( sum += d ) %= 9 ;
    }
    if( sum % 9 == 0 )
        cout << "Yes" << endl ;
    else
        cout << "No" << endl ;
    return 0 ;
}
 