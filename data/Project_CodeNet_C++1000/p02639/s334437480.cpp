#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int   N ;
	string S;
	vector<long long int> X(5);
  
  for(long long int i=0; i < 5; i++) cin >> X[i]; 
  for(long long int i=0; i < 5; i++){
  	if (X[i] == 0) {
      cout << ++i << endl;
      break;
    }
  }
}
