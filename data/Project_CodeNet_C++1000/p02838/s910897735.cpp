#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int INF = 1e9;

int main(){
  long long n;
  const long long max_n = 3 * 1e5;
  long long a[max_n + 1];
  cin >> n;
  for(long long i = 0; i < n; i++) cin >> a[i];

  // long long num[62] = {};
  // for(long long i = 0; i <= 60; i++){
  //   for(long long j = 0; j < n; j++){
  //     if(a[j]&(1LL<<i)) num[i] += 1;
  //   }
  // }
  
  long long ans = 0;
  long long now = 1;
  for(long long i = 0; i <= 60; i++){
    // long long now = (1LL << i);
    // now %= MOD;
    long long x = 0;
    for(int j = 0; j < n; j++) if (a[j]>>i&1) x++;
    now = 1;
    now = x * (n-x) % MOD;
    for(int j = 0; j < i; j++) {
      now = now * 2 % MOD;
    }
    // ans += x * (n-x) * now;
    ans += now;
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}