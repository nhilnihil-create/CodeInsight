#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int INF = 1e9;

int main(){
  long long l,r;
  cin >> l >> r;

  const long long mod = 2019;
  long long ans = 2e9 + 1;
  long long res = 0;
  for(long long i = l; i <= r; i++){
    for(long long j = i+1; j <= r; j++){
      res = i % mod;
      res *= j;
      res %= mod;
      ans = min(ans, res);
      if(ans == 0) break;
    }
    if(ans == 0) break;
  }
  cout << ans << endl;

  // int s = l % mod;
  // vector<int> a;
  // a.push_back(l%mod);
  // int cnt = 0;
  // for(int i = l + 1; i <= r; i++){
  //   if(i%mod == s) {
  //     cnt ++;
  //     if(cnt >= 3) break;
  //   }
  //   a.push_back(i%mod);
  // }
  // sort(a.begin(), a.end());
  // // for(int i = 0; i < a.size(); i++) cout << a[i] << endl;
  // cout << a[0] * a[1] % mod << endl;

  return 0;
}