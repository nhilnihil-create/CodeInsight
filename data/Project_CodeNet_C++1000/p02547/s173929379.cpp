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
  ll N,cnt=0,d1,d2;
  cin >> N;
  string ans="No";
  
  rep(i,N) {
    cin >> d1 >> d2;
    if(d1==d2) {
      cnt++;
      if(cnt==3) ans="Yes";
    }
    else cnt=0;
  }
  
  cout << ans << endl;
  
  return 0;
}
