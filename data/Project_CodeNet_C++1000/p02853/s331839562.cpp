#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int x, y;
  cin >> x >> y;
  
  int m = 0;
  
  if (x == 3)  m += 100000;
  else if (x == 2)  m += 200000;
  else if (x == 1)  m += 300000;
  
  if (y == 3)  m += 100000;
  else if (y == 2)  m += 200000;
  else if (y == 1)  m += 300000;
  
  if (x == 1 && y == 1)  m += 400000;
  
  cout << m << endl;
  
}
