#include<bits/stdc++.h>
using namespace std ;

main(){
	map<string,int> M ;
	string s ;
	int n ;
	
	cin >> n ;
	while(n--){
		cin >> s ;
		M[s]++ ;
	}
	
	cin >> n ;
	int cnt=1 ;
	while(n--){
		cin >> s ;
		if( !M[s] ) cout << "Unknown " << s << endl ;
		else {
			if( cnt%2 ) cout << "Opened by " << s << endl ;
			else cout << "Closed by " << s << endl ;
			cnt++ ;
		}
	}
}