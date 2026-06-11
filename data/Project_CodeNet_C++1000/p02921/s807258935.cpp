#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int i, Size, cnt = 0;
  string S, T;
  cin >> S;
  cin >> T;
  Size = T.size();
  
  for (i = 0; i < Size; i++){
    if (S.at(i) == T.at(i)) cnt++;
  }
 
  cout << cnt << endl;
  return 0;
}