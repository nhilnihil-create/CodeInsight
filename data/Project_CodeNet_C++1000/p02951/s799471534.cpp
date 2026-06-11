#include <bits/stdc++.h>
using namespace std;


int main() {
  int a,b,c;
  
  cin >> a >> b >> c;
  
  a = a-b;
  
  c = c-a;
  
  if(c<0)
    cout << 0;
  else
    cout << c;
}
