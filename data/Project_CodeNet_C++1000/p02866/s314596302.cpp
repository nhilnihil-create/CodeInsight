#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

signed main(){
  int N;
  cin >> N;
  
  vector<int> cnt(N+1);
  for( int i = 0; i < N; i++ ){
    int A;
    cin >> A;
    if( i == 0 && A != 0 ){
      cout << 0 << endl;
      return 0;
    }
    cnt.at(A)++;
  }
  
  int ans;
  //途中で0が出てきたらtrue
  bool z = 0;
  for( int i = 0; i <= N; i++ ){
    if( i == 0 ){ //根
      if( cnt.at(0) != 1 ){
        cout << 0 << endl;
        return 0;
      }
      ans = 1;
    }else{
      if( cnt.at(i) == 0 ) z = 1;
      else{
        if( z ){
          cout << 0 << endl;
          return 0;
        }
        int B = modpow(cnt.at(i-1), cnt.at(i), MOD);
        ans = ans*B%MOD;
      }
    }
  }
  cout << ans << endl;
  
  
}