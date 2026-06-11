#include <bits/stdc++.h>
using namespace std;

inline long long next(long long i) {return i + i/100;}

int main() {
  long long x, y = 0;
  cin >> x;
  
  for (long long i = 100;; i = next(i)) {
    if (i >= x) break;
    y++;
  }
  
  cout << y;
  
  return 0;
}