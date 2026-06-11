#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <stack>

using namespace std;


int main(){

	int n;
 
  while(1){
  	cin >> n;
  	if(n == 0) break;

  	int count = 0;
  	bool s[2*n+1];
  	int era;

  	for(int i=2 ; i<2*n+1 ; i++){
  		s[i] = true;
  	}

  	for(int i=2 ; i*i<(2*n+1) ;i++){
  		if(s[i] != false){
  			era = i;
  			for(int j=2 ; (j*era)<(2*n+1) ; j++){
  				s[j*era] = false;
  			}
  		}
  	}

  	for(int i=n+1 ; i<2*n+1 ; i++){
  		if(s[i] == true) count++;
  	}
  	cout << count << endl;
  }
 

	return 0;
}