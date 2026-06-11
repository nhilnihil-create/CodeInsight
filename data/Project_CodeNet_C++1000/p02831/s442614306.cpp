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
 
 
int32_t main() {
 
 	int a,b;
 	
 	cin >> a >> b;
 	
  
 
 	cout << lcm(a,b) << endl;
 	
 	
 
 
  
}
 
 
 