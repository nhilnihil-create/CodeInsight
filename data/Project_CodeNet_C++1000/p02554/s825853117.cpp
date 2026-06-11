#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  long long power10 = 1;
  for (int i = 0; i < N; i++){
    power10 *= 10;
    power10 %= 1000000007;
  }
  long long power9 = 1;
  for (int i = 0; i < N; i++){
    power9 *= 9;
    power9 %= 1000000007;
  }
  long long power8 = 1;
  for (int i = 0; i < N; i++){
    power8 *= 8;
    power8 %= 1000000007;
  }
  
  long long ans = 1000000007 + power10 - power9;
  ans %= 1000000007;
  ans = ans - power9 + 1000000007;
  ans %= 1000000007;
  ans += power8;
  ans %= 1000000007;
  cout << ans << endl;
}

