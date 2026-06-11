#include<bits/stdc++.h>
using namespace std;

int main(void){
  string S, T;
  int A, B;
  string U;
  cin >> S >> T;
  cin >> A >> B;
  cin >> U;
  if(S == U)
    A--;
  else if(T == U)
    B--;
  cout << A << " " << B << "\n";
  return 0;
} 
