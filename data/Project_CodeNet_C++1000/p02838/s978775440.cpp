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
 
 #define MOD 1000000007;
 
 int arr[300001];
 
int32_t main() {
 	
 	int n;
 	
 	cin >> n;
 	
 	for(int i=0; i<n; i++){	
 	 	cin >> arr[i];
	}
 
 	int ans =0 ;
 	
 	for(int i=0; i<60; i++){
 		
 		int x = 0;
 		
 		for(int j=0; j<n; j++){
 			
 			//int f = 1 << i;
 			
 			if(arr[j] >> i & 1 ){
 				x++;
			}
 		}
 			int now = x* (n-x) % MOD;
 			
 			for(int j=0; j<i; j++){
 				now = now * 2 % MOD;
			}
			 ans += now;
			 ans %= MOD;
		
 		
	 }
 		cout << ans << endl;
 	  
}
 
 
 