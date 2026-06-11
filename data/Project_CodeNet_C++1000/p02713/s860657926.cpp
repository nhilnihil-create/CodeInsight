#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
  if(b == 0) return a;
  
  if(a < b) {
    return gcd(b, a);
  }
  else return gcd(b, a%b);
}

int main() {
  int k;
  cin >> k;
  int sum = 0;
  for(int i = 1; i <= k; i++) {
    for(int j = 1; j <= k; j++) {
      for(int l = 1; l <= k; l++) {
        sum += gcd(i, gcd(j, l));
      }
    }
  }
  cout << sum << endl;
  return 0;
}
  