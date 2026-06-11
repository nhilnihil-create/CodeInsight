#include <bits/stdc++.h>
using namespace std;
int main(){
  int i, j, k, o;
  cin >> i >> j >> k >> o;
  if(o <= i){
    cout << o;
  }
  else if(o - i <= j){
    cout << i;
  }
  else{
    cout << i - (o - i - j);
  }
  return 0;
}