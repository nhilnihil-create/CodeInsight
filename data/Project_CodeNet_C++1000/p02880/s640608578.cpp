#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  bool ans = false;
  
  for (int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(N == (i+1) * (j+1) ){
        ans = true;
        break;
      }
      if(ans) break;
    }
    if(ans) break;
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}