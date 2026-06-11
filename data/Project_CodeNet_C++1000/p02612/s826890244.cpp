#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int n,a;
  cin >> n;
  
  a=n%1000;
  if (a == 0 ) cout << 0 << endl;
  else cout << 1000-a << endl;
  
}