#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int64_t n, a = 0, b = 0, l = 0, r, s = 0, tmp1 = 0, tmp2, d = 0;
  cin >> n;
  vector<int64_t> v(n);
  rep(i, n){
    cin >> v[i];
    s += v[i];
  }
  rep(i, n){
    tmp1 += v[i];
    if(tmp1 > s / 2){
      tmp2 = tmp1;
      tmp1 -= v[i];
      r = i;
      break;
    }
  }
  rep(i, n){
    if(i < r) a += v[i]-1;
    else b += v[i]-1;
  }
  d = min(abs(tmp1 - (s - tmp1)), abs(tmp2 - (s - tmp2)));
  cout << d << endl;
  return 0;
}