#include "bits/stdc++.h"
using namespace std;

int main(){
  
  int N,M;
  long long K;
  cin >> N >> M >> K;
  vector<long long> A(N);
  for(int i=0;i<N;i++) cin >> A[i];
  vector<long long> B(M);
  for(int i=0;i<M;i++) cin >> B[i];
  
  vector<long long> ruiseki_A(N+1);
  ruiseki_A[0] = 0;
  for(int i=1;i<=N;i++)	ruiseki_A[i] = ruiseki_A[i-1] + A[i-1];
  
  vector<long long> ruiseki_B(M+1);
  ruiseki_B[0] = 0;
  for(int i=1;i<=M;i++) ruiseki_B[i] = ruiseki_B[i-1] + B[i-1];
  
  int result = 0;
  for(int i=0;i<=N;i++){
    int t;
    long long K2 = K - ruiseki_A[i];
    if(K2 < 0) break;
    else{
      auto it = upper_bound(ruiseki_B.begin(),ruiseki_B.end(),K2);
      if(it != ruiseki_B.end())
        t = i + distance(ruiseki_B.begin(), it) - 1;
      else
        t = i + M;
      if(result < t) result = t;
    }
  }
  
  cout << result;
  return 0;
}