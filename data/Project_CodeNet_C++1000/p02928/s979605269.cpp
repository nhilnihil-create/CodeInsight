#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
int main(){
  int N;
  long long K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      if (A[i] < A[j]){
        ans += K * (K - 1) / 2 % MOD;
        ans %= MOD;
      }
      if (A[i] > A[j]){
        ans += K * (K + 1) / 2 % MOD;
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}