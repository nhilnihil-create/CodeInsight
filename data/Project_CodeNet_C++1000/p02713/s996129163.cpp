#include <bits/stdc++.h>
using namespace std;

long long gcd(int x, int y, int z) {
  long long a = min(min(x, y), z);
  long long b = 1;
  for(int i = 1; i <=a; i++) {
    if(x%i == 0 && y%i == 0 && z%i == 0) b = i;
  }
  return b;
}
  
int main() {
  
  int K;
  cin >> K;
  vector<int> X(K*K*K);
  
  int ans = 0;
  
  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int l = 1; l <= K; l++) {
        ans += gcd(i, j, l);      
      }
    }
  }
  cout << ans << endl;
}