#include<bits/stdc++.h>
using namespace std;


int main(){
  
  int N, X, i, Sum = 0, D = 0, L;
  cin >> N >> X;
 
  for (i = 0; i < N; i++){
    
    cin >> L;
    D += L;
    if(D > X){
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << N + 1 << endl;
  return 0;
}