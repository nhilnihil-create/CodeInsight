#include <bits/stdc++.h>
using namespace std;
 
int main(){
	long long a=100;
   long long x;
  	cin >> x;
  	int i=0;
  	 
  	while(a<x){
    	a += a/100;
      	
      	i++;
     
    }
  	cout << i << endl;
}