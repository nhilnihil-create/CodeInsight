#include<bits/stdc++.h>
using namespace std ;

main(){
	int n,m,p ;
	int num[110] ;
	
	while( cin >> n >> m >> p , n ){
		int sum = 0 ;
		for( int i=1 ; i<=n ; i++ ){
			cin >> num[i] ;
			sum += num[i] ;
		}
		if( num[m] == 0 ) cout << 0 << endl ;
		else cout << sum*(100-p)/num[m] << endl ;
	}
}