#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string S,T;
  cin >> S;
  cin >> T;
  
  int Sum = 0;
  for(int i=0;i<S.size();i++){
    if(S[i]!=T[i]){ Sum++; }
  }
  
  printf("%d\n", Sum);

  return 0;
}