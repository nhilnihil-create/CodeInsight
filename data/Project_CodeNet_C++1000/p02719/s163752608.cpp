#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t n, k;
  cin >> n >> k;
  
  n %= k;
  if(n>abs(n-k)) n = abs(n-k);
  cout << n << endl;
  return 0;
}