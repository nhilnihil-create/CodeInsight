#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >>X;
  
  int syou = X/100;
  int amari = X%100;
  
  int ans=0;
  
  if(amari<=syou*5)ans =1;
  
  cout << ans << endl;
}