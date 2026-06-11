#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; N--;
  
  int64_t ans = 0;
  
  for (int i = 1; i <= N; i++) ans += N / i;
  
  cout << ans << endl;
  
}