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

int par[200055] ;

int getPar( int x ){
    if( par[x] < 0 )
        return x ;
    return par[x] = getPar(par[x]) ;
}
void unionFind( int x , int y ){
    x = getPar(x) ; y = getPar(y) ;
    if( x != y ){
        par[x] += par[y] ;
        par[y] = x ;
    }
}
int main(){
    FAST_IO ;
    memset(par, -1, sizeof(par)) ;
    int N , M ; cin >> N >> M ;
    for( int i = 1 ; i <= M ; i++ ){
        int x , y ; cin >> x >> y ;
        unionFind(x, y) ;
    }
    int cnt = 0 ;
    for( int i = 1 ; i <= N ; i++ ){
//        cout << par[i] << "," ;
        if( par[i] < 0 )
            cnt = max( cnt , -par[i] ) ;
    }
    cout << cnt << endl ;
    return 0 ;
    
}
 