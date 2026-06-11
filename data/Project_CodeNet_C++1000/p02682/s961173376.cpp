#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,k; cin >> a >> b >> c >>k;
  if(k <= a)
    cout << k;
  else if(k <= a + b)
    cout << a;
  else{
    int amari = k - a - b;
    if(amari < c)
      cout << a - amari;
    else
      cout << a - c;
  }
    
}