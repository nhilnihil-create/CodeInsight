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
 int a[200001];
 
int32_t main() {
 
 	int n;
  
  	cin >> n;
  	
  	for(int i=0; i<n; i++){
  		
  		cin >> a[i];
  		
	}
  
  	int cnt =1;
  	int b=0;
  	vector<int> v;
  	for(int i=0; i<n; i++){
  		
  		if(a[i] != cnt){
  		b++;	
		}
		else{
			v.push_back(cnt);
			cnt++;
			
		}
  		
	}	
	  if(b== n){
  		b= n-1;
  	}
	bool flag = false;
	for(int i=0; i<v.size(); i++){
		if( v[i] == 1)
			flag= true;
	}
 
   if(!flag)
   	b = -1;
  cout << b << endl;
}
 
 
 