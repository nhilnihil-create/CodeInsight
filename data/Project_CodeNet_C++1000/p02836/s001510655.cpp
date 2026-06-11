#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  int i,j,cnt;
  cnt = 0;
  i = 0;
  
  cin >> S;
  j = S.size() - 1;
  
  while(i < j){
      if(S[i] != S[j]){
          cnt++;
      }
      i++;
      j--;
  }
    
  cout << cnt << endl;
  return 0;
}