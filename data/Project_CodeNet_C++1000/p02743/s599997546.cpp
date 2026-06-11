#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
ll a,b,c ;
cin >> a >> b >> c ;
if( c - a - b > 0 && (c - a - b)*( c - a - b ) > 4 * a * b ) cout << "Yes" << endl ;
else cout << "No" << endl ;
}