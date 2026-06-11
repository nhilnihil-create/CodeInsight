#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans = 0;
  cin >> N;
  vector<int> item(N);
  
  for (int i = 0; i < N; i++) cin >> item.at(i);
  for (int j = 0; j < N; j++) {
    for (int k = j+1; k <N; k++) ans += item[j]*item[k];
  }
  
  cout << ans << endl;;
}