#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;
  
  int ans = 0;
  for (int i=0 ; i<3 ; i++){
    if (N.at(i) == '7'){
      ans = 1;
      break;
    }
  }
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}