#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  
  int amax = x / 500;
  int bmax = (x % 500) / 5;
  
  cout << amax * 1000 + bmax * 5 << endl;

  return 0;
}