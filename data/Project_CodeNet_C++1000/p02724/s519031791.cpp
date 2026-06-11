#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int x, hap=0;
  	cin >> x;
  	while(x>=500){
    	x = x-500;
      	hap += 1000;
    }
  	
      while(x>=5){
    	x = x-5;
      	hap += 5;
    }

  	cout << hap << endl;
}