#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9+7;

long long modPow(long long a, long long n, long long p){
  if (n==1LL) return a%p;
  if (n%2LL==0) {
    long long t = modPow(a, n/2LL, p);
    return (t*t)%p;
  }
  return (a * modPow(a, n-1LL, p)) % p;
}

long long combi(long long n, long long k){
  long long child = 1LL;
  long long parent = 1LL;
  for (long long i = 1LL; i <= k; i++) {
    child *= (n-i+1LL);
    child %= MOD;
    parent *= i;
    parent %= MOD;
  }
  return (child * modPow(parent,MOD-2LL, MOD)) % MOD;
}

int main(){
  long long n, a, b;
  cin >> n >> a >> b;

  long long ans = modPow(2LL, n, MOD)-1LL;
  ans -= combi(n,a);
  if (ans < 0) ans += MOD;
  ans -= combi(n,b);
  if (ans < 0) ans += MOD;
  
  cout << ans << endl;
  
}