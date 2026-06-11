#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N,K;
  cin >> N >> K;
  vector<long long>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  vector<long long>counta(N,0);
  vector<long long>countb(N,0);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (A.at(i) < A.at(j)){
        if (i > j){
          counta.at(i)++;
        }
        countb.at(i)++;
      }
    }
  }
  
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += counta.at(i);
  }
  
  long long mod = 1000000007;
  
  long long dis = 0;
  for (int i = 0; i < N; i++) {
    dis += countb.at(i);
    dis %= mod;
  }
  
  long long kaijo = (K * (K-1)/2) % mod;
  
  ans *= K;
  ans %= mod;
  ans += kaijo*dis;
  ans %= mod;
  cout << ans << endl;
}
  
  