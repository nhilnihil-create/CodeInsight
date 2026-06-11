#include <bits/stdc++.h>
using namespace std;

int main(){
 
  long long X,m;
  cin >> X;
  
  m = 100;
  int ct = 0;
  
  while(m < X){
    m += m/100;
    ct++;
  }
  cout << ct << "\n";

  return 0;
}