#include<bits/stdc++.h>
using namespace std; 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  long long x, k, d;
  cin >> x >> k >> d;
  if (x < 0) x = abs(x);
  long long move = min(k, x / d);
  k -= move;
  x -= move * d;
  if (k & 1) {
    x = min(abs(x + d), abs(x - d));
  }
  cout << x << "\n";
}