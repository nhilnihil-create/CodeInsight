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
 
//#define int long long
 

long long gcd(long long a, long long b){
	
	if(b==0){
		return a;
	}
	
	gcd(b,a%b);
	
}

long long LCM(long long a, long long b){
	
	
return a/gcd(a, b) * b;  
	
	
}

 
int f(int x){
	
	
	int res = 0;
	
	while( x%2 == 0){
		
		x/=2;
		res++;
	}
	
	return res;
	
}

 
int main() {
 
 	long long a,b;
 	
 	cin >> a >> b;
 	
  
 
 	cout << a/__gcd(a,b)*b << endl;
 	
 	
 
 
  
}






