#include <bits/stdc++.h>

using namespace std ;

int main(){
	
	int n , m ;
	
	cin>>n ;		
	cin>>m ;		
	
	
	float comb_n , comb_m ;
	
	comb_n= (float)n * (((float)n/2) -0.5 ) ;
	comb_m = (float)m * (((float)m/2) -0.5 )  ;
	

	int ans = (int)comb_n + (int)comb_m ;
	cout<<ans ;
	
	return 0 ;
}