#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

ll n, m, f = 1, b;

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    f = f * a / gcd(f, a);
    ll cnt = 0;
    while(a % 2 == 0) {
      a /= 2;
      cnt++;
    }
    if (i == 0) {
      b = cnt;
    } else {
      if (b != cnt) {
        cout << 0 << endl;
        return 0;
      }
    }
  }
  
  cout << (m + f/2) / f << endl;
  return 0;
}