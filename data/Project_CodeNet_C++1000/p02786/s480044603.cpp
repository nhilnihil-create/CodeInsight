#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll x = 1, y = 1;
  if(n!=1) {
    while(true) {
      if(n!=1) {
        n /= 2;
        x *= 2;
        y += x;
      }
      else break;
    }
    cout << y << endl;
  }
  else cout << 1 << endl;
  return 0;
}