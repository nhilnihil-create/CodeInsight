#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int N;
  	cin >> N;
  
  	int a = 0;
  	for(int i=0;i<=10;i++){
    	if(N <= 1000*i){
          a = 1000*i - N;;
        break;
        }
    }
  	
  	cout << a << endl; 
}