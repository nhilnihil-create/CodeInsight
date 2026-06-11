#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

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
  int n;
  ll MOD = 998244353;
  cin >> n;
  vector<int>d(n);
  rep(i,0,n) cin >> d[i];
  if(d[0] != 0){
    cout << 0 << endl;
    return 0;
  }
  sort(d.begin(),d.end());
  vector<int>c(d[n-1]+1);
  rep(i,0,n) c[d[i]]++;
  if(c[0] != 1){
    cout << 0 << endl;
    return 0;
  }
  rep(i,1,c.size()){
    if(c[i] == 0){
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  rep(i,2,c.size()){
    ans *= modpow(c[i-1],c[i],MOD);
    ans %= MOD;
  }
  cout << ans << endl;
}