#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int d[k], a[k][n];
  vector<bool> tricked(n, true);
  for (int i = 0; i < k; i++) {
    cin >> d[i];
    for (int j = 0; j < d[i]; j++) {
      cin >> a[i][j];
      tricked[a[i][j] - 1] = false;
    }
  }
  
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (tricked[i]) count++;
  }
  
  cout << count;
  
  return 0;
}