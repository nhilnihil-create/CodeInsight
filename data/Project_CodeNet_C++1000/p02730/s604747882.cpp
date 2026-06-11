#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

bool kaibun( string s ){
    string t = s ;
    reverse(s.begin(),s.end()) ;
    if( s == t )return true ;
    else return false ;
}

int main(){
    string s ;
    cin >> s ;
    ll n = s.size() ;
  	//cout << s.substr(0,(n-1)/2 ) <<endl;
  	//cout << s.substr( (n+3)/2-1 , (n-3)/2+1 ) << endl;
  	if(kaibun(s)){
    	if( kaibun( s.substr(0,(n-1)/2) ) ){
        	if( kaibun( s.substr( (n+3)/2-1, (n-3)/2+1) ) ) {
            	cout << "Yes" << endl ;
            	return 0 ;
        	} 
    	}
  	}
    cout << "No" << endl ;    
}