#include<bits/stdc++.h>
using namespace std ;

#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define pb push_back

signed main(){
	int L, R, d, c = 0 ;
	cin >> L >> R >> d ;
	cout << R / d - (L-1) / d ;
	return 0 ;
}