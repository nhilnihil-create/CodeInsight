#include <bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  
  while (true){
    int num = 2;
    while (num <= pow(X, 0.5)){
      if (X % num == 0){
        X++;
        break;
      }
      num++;
    }
    
    if (num > pow(X, 0.5)){
      break;
    }
  }
  
  cout << X << endl;
      
}