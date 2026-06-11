#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin >> N;

  int x;
  x = N*100/108;
  
  int M;
  M = x*108/100;
  
  int L;
  L = (x+1)*108/100;
  
  if(M==N){ 
  cout << x << endl;
  }
  else if(L==N){
    cout << x+1 << endl;
  }
  else {
    cout << ":(" << endl;
  }
      
  return 0;
}

