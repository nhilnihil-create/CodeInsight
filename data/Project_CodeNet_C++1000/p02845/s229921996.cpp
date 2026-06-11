#include <iostream>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
using ll = long long;
const int MOD = 1000000007;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll red = -1;
  ll blue = -1;
  ll yellow = -1;
  ll ans = 1;
  rep(i, n) {
    cin >> a[i];
    if(red == blue && blue == yellow) {
      if(a[i] == red + 1) {
        ans *= 3;
        red++;
      }
      else ans = 0;
    }
    else if(red == blue) {
      if(a[i] == red + 1) {
        ans *= 2;
        red++;
      }
      else if(a[i] == yellow + 1) yellow++;
      else ans = 0;
    }
    else if(blue == yellow) {
      if(a[i] == blue + 1) {
        ans *= 2;
        blue++;
      }
      else if(a[i] == red + 1) red++;
      else ans = 0;
    }
    else if(red == yellow) {
      if(a[i] == yellow + 1) {
        ans *= 2;
        yellow++;
      }
      else if (a[i] == blue + 1) blue++;
      else ans = 0;
    }
    else if(a[i] == red + 1) red++;
    else if(a[i] == blue + 1) blue++;
    else if(a[i] == yellow + 1) yellow++;
    else ans = 0;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
