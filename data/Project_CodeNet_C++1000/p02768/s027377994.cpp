#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

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
  ll n, a, b;
  cin >> n >> a >> b;
  ll sum = myPow(2, n, mod);
  sum--;
  ll bunsiA=1, bunboA=1;
  rep(i, a){
    bunsiA *= (n-i);
    bunsiA %= mod;
  }
  rep(i, a){
    bunboA *= i+1;
    bunboA %= mod;
  }
  ll A = bunsiA * modinv(bunboA, mod) % mod;
  ll bunsiB=1, bunboB=1;
  rep(i, b){
    bunsiB *= (n-i);
    bunsiB %= mod;
  }
  rep(i, b){
    bunboB *= i+1;
    bunboB %= mod;
  }
  ll B = bunsiB * modinv(bunboB, mod) % mod;
  sum -= A;
  sum %= mod;
  if(sum < 0) sum += mod;
  sum -= B;
  sum %= mod;
  if(sum < 0) sum += mod;
  cout << sum << endl;
  return 0;
}
  
  
