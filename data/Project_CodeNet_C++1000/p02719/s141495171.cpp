#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, K, b, b2;
  cin >> N >> K;
  b = N % K;
  b2 = abs(b - K);
  cout << min(b, b2);
  return 0;
}