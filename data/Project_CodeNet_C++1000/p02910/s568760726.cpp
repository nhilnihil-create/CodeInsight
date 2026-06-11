#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int N = S.size();
  
  bool Ans = true;
  
  for(int i=0;i<N;i++){
    if(i%2==0){
      if(S.at(i) != 'R'&&S.at(i)!='U'&&S.at(i)!='D'){
        Ans = false;
      }
    } else {
      if(S.at(i) != 'L'&&S.at(i)!='U'&&S.at(i)!='D'){
        Ans = false;
      }
    }
  }
  
  if(Ans == true){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
