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
  int n, b;
  cin >> n >> b;
  int rr = n - b;
  ll M = mod - 2;
  cout << rr + 1 <<endl;
  for (int i = 2; i <= b; i++) {
    
    //bp = b-1Ci
    ll bp = 1;
    ll bw = 1;
    for (int j = b - 1; j > b - i; j--) {
      bp = bp * j % mod;
      bw = bw * (b - j) % mod;
    }
    bw = r(bw, M);
    bp = bp * bw % mod;
    
    //ap
    ll ap = 1;
    ll aw = 1;
    for (int j = 0; j < i; j++) {
      ap = ap * (rr + 1 - j) % mod;
      aw = aw * (j + 1) % mod;
    }
    aw = r(aw, M);
    ap = ap * aw % mod;
    
    ll K = ap * bp % mod;
    printf("%lld\n", K);
  }
}