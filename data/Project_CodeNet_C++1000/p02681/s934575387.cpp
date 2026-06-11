#include <bits/stdc++.h>
 using namespace std;

int main(){
  string S,T;
  cin >> S >> T;

  bool flg = true;
  if (S.size()+1 == T.size()){
    for(int i=0;i<S.size();i++)
      if (S[i] != T[i]){
        flg = false;
        break;
      }
  }
  else
    flg = false;
  
  if (flg)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}