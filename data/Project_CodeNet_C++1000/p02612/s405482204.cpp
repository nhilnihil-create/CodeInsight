#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int X = N%1000;
  if(X ==0){
    cout << 0 << endl;
  }else{
    cout << 1000 - X;
  }
  
  return 0;
}