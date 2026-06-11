#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){

  int cnt;
  int a;
  cin >> a; //価格を入力する
  
  cnt = a + a*a + a*a*a;
  
  cout << cnt << endl;
  
  return 0;
}