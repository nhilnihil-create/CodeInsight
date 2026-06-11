#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}
  
int main() {
  int n , p;
  string S;
  cin >> n >> p >> S;
  vector<int> s(n);
  for (int i = 0; i < n; i++) {
    s[i] = S[i] - '0';
  }
  ll c = 0;
  
  if (p == 2) {
    for (int i = n-1; i >= 0; i--) {
      if (s[i] % 2 == 0) {
        c += (i + 1);
      }
    }
  }
  else if (p == 5) {
    for (int i = n-1; i >= 0; i--) {
      if (s[i] % 5 == 0) {
        c += (i + 1);
      }
    }
  }
  
  
  else{
  vector<ll> k(p);
  vector<ll> a(n+1, 0);
  k[0]++;
  ll p10 = 1;
  for (int i = n-1; i >= 0; i--) {
    a[i] = (p10 * s[i] + a[i+1]) % p;
    p10 *= 10;
    p10 %= p;
    k[a[i]]++;
  }
  for (int i = 0; i < p; i++) {
    if (k[i] > 1) {
      c += (k[i] * (k[i] - 1) / 2);
    }
  }
  
  }
  printf("%lld\n", c);
} 

