#include <bits/stdc++.h>
using namespace std;

int N,M,K;

int main(){
  cin >> N >> M >> K;
  vector<long long> A(N+1);
  for(int i = 0; i < N; i++){
    cin >> A[i+1];
    A[i+1] += A[i];
  }
  
  vector<long long> B(M+1);
  for(int i = 0; i < M; i++){
    cin >> B[i+1];
    B[i+1] += B[i];
  }
  int ans = 0;
  int last = M;
  for(int i = 0; i <= N; i++){
    if(A[i] > K) break;
    while(B[last] > K-A[i]){
      last -= 1;
    }
    ans = max(ans,i+last);
  }
  cout << ans << endl;
}
