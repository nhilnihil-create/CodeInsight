#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K; cin >> N >> K;
  
  int64_t maxSum = 0, indexMemo = 0; double ans = 0;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  vector<int64_t> vecSum(N + 1, 0);
  
  for (int i = 0; i < N; i++) vecSum[i + 1] = vecSum[i] + vec[i];
  
  for (int i = 0; i <= N - K; i++) {
    
    int left = i, right = i + K;
    
    int64_t tmpSum = vecSum[right] - vecSum[left];
    
    if (maxSum < tmpSum) { maxSum = tmpSum; indexMemo = i; }
    
  }
  
  for (int i = indexMemo; i < indexMemo + K; i++) {
    
    int tmp = vec[i];
    
    ans = ans + double(tmp + 1) / 2;
    
  }
  
  cout << fixed << setprecision(10);
  
  cout << ans << endl;
  
}