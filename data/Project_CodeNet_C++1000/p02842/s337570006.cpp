#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int flag = 0;
 // int X = N*100/108-10;
  
  for(int i = 0 ; i <= N; i++){
  	if(N==8*i/100+i){
      cout << i << endl;
      flag = 1;
      break;
    } 
  }
  if(flag == 0){
  	cout << ":(" << endl;
  }

  return 0;
}
