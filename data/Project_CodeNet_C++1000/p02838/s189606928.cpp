#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9
#define PI 3.14159265359
#define MOD 1000000007
#define ALL(v) v.begin(),v.end()
#define ALLR(v) v.rbegin(),v.rend()
typedef long long ll;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
//isPrime
//modpow modinv
//getDigit
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
      a = a * a % mod;
      n >>= 1;
    }
        return res;
}

long long modinv(long long a,long long mod){
  return modpow(a,mod-2,mod);
}

long long int modfact(long long int n,long long int mod){
  if(n){
    return n*modfact(n-1,mod)%mod;
    }else{
      return 1;
    }
}
int main() {
  cout << fixed << setprecision(10);
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll ans = 0;
  rep(i,60){
    ll p = 0;
    rep(j,n){
      if(a[j]&(1LL<<i)){
        p++;
      }
    }
    ans+=p*(n-p)%MOD*modpow(2,i,MOD)%MOD;
    
    ans%=MOD;
  }
  cout << ans << endl;
}