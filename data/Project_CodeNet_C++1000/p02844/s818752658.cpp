#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  int ans = 0;
  // 全探索
  for (int i = 0; i < 1000; i++) {
    int c[3] = {i / 100, (i/10) % 10, i % 10};
    
    int ind = 0;
    for (int j = 0; j < N; j++) {
      if (S[j] == '0' + c[ind]) ind++;
      
      if (ind == 3) {
        ans++;
        break;
      }
    }
    
  }
  
  cout << ans << endl;
}