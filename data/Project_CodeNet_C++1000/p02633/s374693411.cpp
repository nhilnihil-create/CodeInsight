#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  int x;
  cin >> x;
  int k = 360 / gcd(360, x);
  cout << k << endl;
  return 0;
}