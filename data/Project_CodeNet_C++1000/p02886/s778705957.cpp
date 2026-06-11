#include <bits/stdc++.h>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
const int MOD = 1000000007;

long long mod(long long val, long long m) {
  long long res = val % m;
  if (res < 0) res += m;
  return res;
}

bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}

int main() {
  ll N,ans=0;
  cin >> N;
  vector<ll> d(N);
  rep(i,N) cin >> d[i];
  
  for(int i=0;i<N-1;i++){
    for(int j=i+1;j<N;j++){
      ans += d[i]*d[j];
    }
  }
  cout << ans << endl;
  
  return 0;
}
