#include <bits/stdc++.h>

#define tam(s) s.length()

using namespace std ;

int main(){
	string s , rev ;
	int t ;

	do{
		cin>>s ;
	}while(tam(s) %2 == 0) ;	
	
	t=tam(s) ;
	
	
	
	rev=s ;
 	reverse(rev.begin(), rev.end()); 
 	
 	
 	int s1 = ((t-1)/2) , s2=((t+3)/2) ;

	string sub1 = s.substr(0 , s1) ;		
	string sub2 = s.substr(s2-1 , s1 ) ;	
	string v1=sub1 ; 
	string v2=sub2 ;
	
	
	
	if(s.compare(rev) == 0){
		reverse(v1.begin(), v1.end()) ;
		reverse(v2.begin(), v2.end()) ;
		
		if ( (sub1.compare(v1) == 0) && (sub2.compare(v2) == 0)  ) cout<<"Yes" ;
		else cout<<"No" ;	
	}
	else cout<<"No" ;
	
	return 0 ;
}