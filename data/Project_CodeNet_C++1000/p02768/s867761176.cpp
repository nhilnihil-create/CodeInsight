#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define INF 1<<29
#define LIMIT 1000000007 //10^9+7

namespace /* combination.cpp */{
  namespace /* modinv.cpp */{
    namespace /* extGCD.cpp */{
      //ax + by = gcd(a, b)を満たすx, yを参照渡しから入れる
      long long extGCD(long long a, long long b, long long &x, long long &y) {
          if (b == 0) {
              x = 1;
              y = 0;
              return a;
          }
          long long d = extGCD(b, a%b, y, x);
          y -= a/b * x;
          return d;
      }
    }

    /*
    mod pでの a の逆元 x
    ax = 1 mod p
    ax-1がpで割り切れるので
    ax + py = 1 の解 x をとる
    aとpは互いに素であること
    */
    long long modinv(long long a, long long p){
      long long x, y;
      extGCD(a, p, x, y);
      return (x>0? x: x+p);
    }
  }

  long long l_fac(long long n){
    if(n<0) return -1;
    long long ans = 1;
    for(long long i=1; i<=n; i++){
      ans *= i;
      ans %= LIMIT;
    }
    return ans;
  }

  long long l_nPr(long long n, long long r){
    long long ans = 1;
    for(long long i=0; i<r; i++){
      ans *= (n-i);
      ans %= LIMIT;
    }
    return ans;
  }

  long long l_nCr(long long n, long long r){
    if(r > n/2) r = n-r;
    return l_nPr(n, r) * modinv(l_fac(r), LIMIT) % LIMIT;
  }
}

long long modpow(long long a, long long n, long long p){
  if(n==1) return a % p;
  if(n%2 == 1) return (a * modpow(a, n-1, p)) % p;

  long long t = modpow(a, n/2, p);
  return t * t % p;
}

int main(){
    ll n, a, b;
    cin>>n>>a>>b;

    ll ans = modpow(2, n, LIMIT) - 1;
    ans -= l_nCr(n, a);
    if(ans<0)ans+=LIMIT;
    ans -= l_nCr(n, b);
    if(ans<0)ans+=LIMIT;

    cout<<ans<<endl;
}