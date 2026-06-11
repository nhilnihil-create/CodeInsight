#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> S.at(i);
  }
  sort(S.begin(), S.end());
  for (int i = 0; i < N; i++) {
    bool memo = true;
    if (i != N - 1) {  
      if (S.at(i) == S.at(i + 1)) {
        memo = false;
      }    
    }
    if (memo == true) {
      ans++;
    }
  }
  cout << ans << endl;
}