#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll K;

ll gcd(ll a, ll b) {
  if (a % b == 0) {
    return (b);
  } else {
    return (gcd(b, a % b));
  }
}

int main() { 
    cin >> K;
    ll out = 0;
    for (ll i = 1; i <= K; i++) {
      for (ll j = 1; j <= K; j++){
        for (ll k = 1; k <= K; k++){
          ll tmp = gcd(i, j);
          out += gcd(tmp, k);
        }
      }
    }
    cout << out << endl;
    return 0;
}