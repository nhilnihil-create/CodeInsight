#include<bits/stdc++.h>
using namespace std;

int string_len(char str[]){
  int len = 0;
  while(str[len])
    len++;
  return len;
}

int main(void){
  char S[50];
  char T[50];
  bool ans = true;
  cin >> S >> T;
  int len = string_len(S);
  for(int i = 0; i < len; i++){
    if(S[i] != T[i]){
      ans = false;
      break;
    }
  }
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}