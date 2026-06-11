#include <iostream>
#include <cmath>
#include <stdint.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
using namespace std;
 
#define int long long
 

int gcd(int a, int b){
	
	if(b==0){
		return a;
	}
	
	gcd(b,a%b);
	
}

int LCM(int a, int b){
	
	
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


int prime(int n){
	
	for(int i=n; i<=INT_MAX; i++){
		
		bool flag = true;
		for(int j=2; j<i; j++){
			
			if(i%j == 0){
				flag = false;
				break;
			}
			
		}
		if(flag)
			return i;
	}
	
	
	
}
 
int32_t main() {
 
 	int x;
 	
 	cin >> x; 
 	
 	cout << prime(x) << endl;
 	
}






