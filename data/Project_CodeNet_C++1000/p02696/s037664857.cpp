#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
using namespace std;

#define int long long

int32_t main() {
//	cout << fixed << setprecision(25);
	//int t;
	
	//cin >> t;
	
//	while(t--){
		
	   int A,B,N;
	   
	   cin >> A >> B >>N;
	  
	   double x =  min (B-1,N);
	   
		 double  ans = floor( (A*x) /B) - A * floor(x/B) ;
	    
	 cout << ans << endl;
		
//	}
	
	
}