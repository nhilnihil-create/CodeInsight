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


 
int32_t main() {
 
 
 	int n,k;
 	
 	cin >> n >> k;
 	
 	int r,s,p;
 	
 	cin >> r >> s >>p;
  
  	string t;
  	
  	cin >> t;
  	
  	int point = 0;
  	int sz = t.length();
  	vector<int> v(sz);
  	
  	
  	for(int i=0; i<sz; i++){
  	 
  	 	if(i-k >=0 && v[i-k] && t[i] == t[i-k])
  	 	continue;
  	 
  	 
  	 	if(t[i] == 'r') point+= p;
  	 	if(t[i] == 's') point+= r;
  	 	if(t[i] == 'p') point+= s;
  	 	
  	 	v[i] = 1;
	}
 
 	cout << point << endl;
}






