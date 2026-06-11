#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
  int x, y;
  cin >> x >> y;
  if((x+y) % 3 != 0){
    cout << 0 << endl;
    return 0;
  }
  int m = (2*y-x)/3, n = (2*x-y)/3;
  if(m < 0 || n < 0){
    cout << 0 << endl;
    return 0;
  }
  ll bunsi = 1;
  ll bunbo = 1;
  rep(i, m){
    bunsi *= m+n-i;
    bunsi %= mod;
  }
  rep(i, m){
    bunbo *= m-i;
    bunbo %= mod;
  }
  ll res = bunsi * modinv(bunbo, mod) % mod;
  cout << res << endl;
  return 0;
}
  