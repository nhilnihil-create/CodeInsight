#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N;
  cin >> N;
  vector<long long> A(N);
  for (long long i = 0; i < N; i++){
    cin >> A[i];
  }
  
  long long ans = 0;
  for (long long i = 0; i < N - 1; i++){
    if (A[i] > A[i + 1]){
      ans += A[i] - A[i + 1];
      A[i + 1] = A[i];
    }
  }
  
  cout << ans << endl;
}