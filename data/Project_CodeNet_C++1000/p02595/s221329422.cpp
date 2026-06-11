#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int N, D;
  	cin >> N >> D;
  	int X, Y;
  	
   int  res = 0;
  	for(int i=0;i<N;i++){
    	cin >> X >> Y;
      
      if(pow(D, 2.0) >= pow(X, 2.0) + pow(Y, 2.0)) res++;
    }
  	cout << res << endl;
}