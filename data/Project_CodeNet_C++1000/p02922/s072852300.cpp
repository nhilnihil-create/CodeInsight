#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int A,B,N;
  	cin >> A >> B;
  	N= (B-1)/(A-1);
  	
  	if((B-1)%(A-1)==0){
  		cout << N << endl;
    }
  
  	else{
    	cout << N+1 << endl;
    }
  	
}