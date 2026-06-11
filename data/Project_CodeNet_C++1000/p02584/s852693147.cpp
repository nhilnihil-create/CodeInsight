#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t x, k, d;
  cin >> x >> k >> d;
  int64_t xx;
  if (x <= 0){
    xx = (-1) * x;
  }
  else {
    xx = x;
  }
  int64_t a = xx / d;
  int64_t ans;
  if (k <= a){
      ans = xx - k * d;
    }
  else {
      ans = xx - a * d;
      if((k - a) % 2 == 1){
        ans = (d - ans);
      }
  }
  cout << ans;
}

