#include<bits/stdc++.h>
using namespace std;

int main(void){
  char S[3], T[3];
  int cnt = 0;
  cin >> S >> T;
  for(int i = 0; i < 3; i++){
    if(S[i] == T[i])
      cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
  
