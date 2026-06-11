#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string.h>
#include <set>
using namespace std;
 
#define int long long
 
 
int gcd(int a, int b){
	
	if(b==0){
		return a;
	}
	
	return gcd(b,a%b);
	
}
 
 int lcm(int a, int b)  
 {  
    return (a*b)/gcd(a, b);  
 }  
 
 
int f(int x){
	
	
	int res = 0;
	
	while( x%2 == 0){
		
		x/=2;
		res++;
	}
	
	return res;
	
}
int g[16][16];
 
int32_t main() {
 	
 
 	
 	int n;
 	
 	cin >> n;
 	
 	for(int i=0; i<n; i++){
 		
 		for(int j=0; j<n; j++){
 			
 			g[i][j] = -1;
 			
 			
 			
		}
 		
	 }
 		
 		
 		
 		
 	for(int i=0; i<n; i++){
 		
 		int m;
 		cin >> m;
 	 
 		for(int j=0; j<m; j++){	
		 	int x, y;		 
			cin >> x >> y;	
			x--;		
		 	g[i][x] = y;
		}
 		
	 }
 
 	 int ans =0 ;
	  
	  for(int i=0; i< 1<<n; i++ ){
	  	
	  	vector<int> d(n);
	  	
	  	for(int  j=0; j<n; j++){
	  		int f = 1 << j;
		  if(i & f) {
		  	d[j] = 1;
		  }	
	  		
		}
	  	
	  	bool ok =true;
	  	for(int j=0; j<n; j++){
	  		
	  		if(d[j]){
	  			
	  			for(int k=0; k<n; k++){
	  			
				  	if(g[j][k] == -1)
				  		continue;
	  				if(g[j][k] != d[k])
	  					ok = false;
				}
	  			
			}
		  	
		}
	  	
	  			  	
		  	if(ok){
		  		int tmp = __builtin_popcount(i);
			  	if(tmp > ans){
			  		ans = tmp;
				}
		  	 
		  	}
	  	 
	  } 
 	 
 	  	cout << ans << endl;
 	  
 	  
}
 
 
 