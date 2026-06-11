#include <bits/stdc++.h>
using namespace std;

int main() {

  string S;
  cin >> S;
  
  int N = size(S);
  
  int check1 = 0;
  int check2 = 0;
  
  for(int i = 0; i <= (N-1)/2; i++) {
    if(i == (N-1)/2) {
      check1 = 1;
      break;
    }
    if(S.at(i) != S.at(N-1-i)) break; 
  }
  
  for(int i = 0; i <= (N-1)/2; i++) {
    if(i == (N-1)/2) {
      check2 = 1;
      break;
    }
    if(S.at(i) != S.at((N-1)/2-1-i)) break; 
  }
  
  if(check1*check2 == 1) cout << "Yes" << endl;
  else cout << "No" << endl;
  
}