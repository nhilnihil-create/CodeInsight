#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  
  int amari = X%100;
  int shou = X/100;
  
  if(X>=100 && amari<=shou*5){cout << 1 << endl;}
  else{cout << 0 << endl;}
  
}