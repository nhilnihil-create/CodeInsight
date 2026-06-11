#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  int K;
  cin >> K;
  
  queue <long> q;
  for (int i = 1; i <= 9; ++i) {
    q.push(i);
  }
  
  int cnt = 0;
  long ans;
  while (cnt < K) {
    ans = q.front();
    cnt++;
    q.pop();
    
    for (int i = max(0L, ans % 10 - 1);
         i <= min(9L, ans % 10 + 1);
         ++i) {
      q.push(ans * 10 + i);
    }
  }
  
  cout << ans << endl;
  return 0;
}