#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

i64 dp[3005][3005];
i64 N, S;
const i64 MOD = 998244353LL;

i64 rot(int n){
  for(i64 i=1;;i++){
    n -= i;
    if(i >= n) return i;
  }
}

int main(){
  vector<bool> isprime(1000005, true);
  isprime[0] = isprime[1] = false;
  for(int i=2;i<=1000005;i++){
    if(!isprime[i])continue;
    for(int j=2;i*j<=1000005;j++){
      isprime[i*j] = false;
    }
  }
  i64 N, T;
  cin >> N;
  T = N;
  map<i64, i64> factors;
  for(i64 i=2;i<=T&&i*i<=N;i++){
    if(!isprime[i])continue;
    while(T % i == 0){
      factors[i]++;
      T /= i;
    }
  }
  if(T != 1)factors[T]++;
  i64 ret = 0;
  for(auto&& p:factors){
    cerr << p.first << " " << p.second << endl;
    ret += rot(p.second);
  }
  cout << ret << endl;
}
