#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  int ans = 1;
  int n = s.size();
  int half = (n-1)/2;
  for (int i=0 ; i<half ; i++){
    if (s.at(i) != s.at(n-1-i)){
      ans = 0;
      break;
    }
  }
  if (ans == 1){
    if (half%2 == 0){
      for (int i=0 ; i<half/2 ; i++){
        if (s.at(i) != s.at(half-1-i)){
          ans = 0;
          break;
        }
      }
    }
    else{
      for (int i=0 ; i<(half-1)/2 ; i++){
        if (s.at(i) != s.at(half-1-i)){
          ans = 0;
          break;
        }
      }
    }
  }
  
  if (ans == 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}