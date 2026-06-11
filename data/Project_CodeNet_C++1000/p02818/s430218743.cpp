#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

static const int MAX = 200000;

int main() {
  ll a,b,k;
  cin >> a >> b >> k;
  if (a >= k) {
    a -= k;
  } else {
    k -= a;
    a = 0;
    if (b >= k) {
      b -= k;
    } else {
      k -= b;
      b = 0;
    }
  }
  cout << a << " " << b << endl;
}
