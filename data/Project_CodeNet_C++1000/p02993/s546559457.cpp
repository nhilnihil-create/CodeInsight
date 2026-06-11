#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[4];
  bool ans = true;
  cin >> S;
  for(int i = 0; i < 3; i++){
    if(S[i] == S[i + 1])
      ans = false;
  }
  if(ans) cout << "Good" << "\n";
  else cout << "Bad" << "\n";
  return 0;
}   
