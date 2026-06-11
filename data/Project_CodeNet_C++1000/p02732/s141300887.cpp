#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0; int count = 1;
  
  vector<int64_t> vec(N), sortedVec(N), countMemo(N + 1);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  sortedVec = vec;
  
  sort(sortedVec.begin(), sortedVec.end());
  
  for (int i = 0; i < N - 1; i++) {
    
    int64_t tmp = sortedVec[i], next = sortedVec[i + 1];
    
    if (tmp == next) count++;
    
    else {
      countMemo[tmp] = count;
      count = 1;
    }
    
    if (i == N - 2) countMemo[next] = count;
    
  }
  
  for (int64_t x : countMemo) {
    
    if (x < 2) continue;
    
    sum += x * (x - 1) / 2;
    
  }
  
  for (int x : vec) {
    
    int64_t tmp = countMemo[x];
    
    if (tmp < 2) cout << sum << endl;
    
    else cout << sum - tmp + 1 << endl;
    
  }
  
}