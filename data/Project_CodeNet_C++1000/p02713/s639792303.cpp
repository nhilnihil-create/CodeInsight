#include <bits/stdc++.h>
using namespace std;

int main(){
  int K;
  cin >> K;
  long long ans = 0;
  
  for (int i = 1; i <= K; i ++) {
    for (int j = 1; j <= K; j++) {
      for (int k = 1; k <= K; k++) {
        ans = ans + gcd(gcd(j, k), i);
      }
    }
  }
  cout << ans << endl;
}