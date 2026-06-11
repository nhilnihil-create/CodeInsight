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
 
#define MOD 1000000007
 
int power(int a, int b, int m = MOD) {
    a%=m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}

 int arr[300001];
 
int32_t main() {
 	
 	int n;
 	
 	cin >> n;
 	
 	for(int i=0; i<n; i++){	
 	
 	 	cin >> arr[i];
 	 	
	}
 	
 	int one[64]{};
 	int zero[64]{};
 
 	for(int i=0; i<n; i++){
 		
 		int tmp = arr[i]; 
 			int k =0;
 		while(tmp){
 			
 			if(tmp &1){
 				
 				one[k]++;
 				
			}
 			else{
 				zero[k]++;
			}
 			
 			tmp/=2;
 			k++;
 			
		}
 		
 		for(int j=k; j<=63; j++){
 			
 			zero[j]++;
 			
		}
 		
 		
	}
	
 	
 	int ans = 0;
 	 for(int i=0; i<64; i++){
 	 	
 	   if(one[i] != 0 && zero[i] != 0){
		 
 		int s = (one[i]%MOD*zero[i]%MOD)%MOD;
	   	
	   	s = (s%MOD *power(2,i,MOD)% MOD )%MOD;
	   	
	   	ans = (ans%MOD + s%MOD ) % MOD;
	   }
 	 	
	}
 	
 	cout<<ans << endl;
 	  
}
 
 
 