#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  if ((b-a)%2 == 0) 
    if (b-a >= 0) cout << a+(b-a)/2 << endl;
    else cout << b+(a-b)/2 << endl;
  else cout << "IMPOSSIBLE" << endl;
  
}