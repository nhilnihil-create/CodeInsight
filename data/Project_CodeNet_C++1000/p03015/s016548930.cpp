#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000000 + 7;

int64_t f1(int x) {
  if(x == 0) {
    return 1;
  }
  else {
    int64_t ans = f1(x / 2) * f1(x / 2);
    ans %= MOD;
    if(x % 2 == 1) {
      ans *= 3;
      ans %= MOD;
    }
    return ans;
  }
}

int64_t f2(int x) {
  if(x == 0) {
    return 1;
  }
  else {
    int64_t ans = f2(x / 2) * f2(x / 2);
    ans %= MOD;
    if(x % 2 == 1) {
      ans *= 2;
      ans %= MOD;
    }
    return ans;
  }
}
  
    
int main() {
  string L;
  cin >> L;
  int64_t ans = 0;
  int64_t keep = 1;
  for(int i = 0; i < L.size() - 1; i++) {
    if(i == 0) {
      ans += 1;
      keep *= 3;
    }
    else {
      ans += keep;
      ans %= MOD;
      keep *= 3;
      keep %= MOD;
    }
  }
  int count = 0;
  for(int i = 1; i < L.size(); i++) {
    if(L.at(i) == '1') {
      ans += (f1(L.size() - i - 1) * f2(count)) % MOD;
      ans %= MOD;
      count += 1;
    }
  }
  ans += f2(count);
  ans %= MOD;
  ans *= 2;
  ans %= MOD;
  ans += 1;
  cout << ans << endl;
}