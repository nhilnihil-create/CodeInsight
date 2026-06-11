#include <bits/stdc++.h>
using namespace std;;

int threeGCD (int a, int b, int c) {
  return __gcd(__gcd(a,b),__gcd(b,c));
}

int main() {
  int K; cin >> K;
  int ans =0;
  for (int i =1; i<=K; i++) {
    for (int j =1; j<=K; j++) {
      for (int k =1; k<=K; k++) {
        ans += threeGCD(i,j,k);
      }
    }
  }
  cout << ans << endl;
}
  