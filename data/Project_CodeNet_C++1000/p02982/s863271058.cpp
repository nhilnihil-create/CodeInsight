#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  vector<vector<int>> xij(n, vector<int>(d));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      cin >> xij.at(i).at(j);
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      int sum = 0;
      for (int k = 0; k < d; k++) {
        int a = abs(xij.at(i).at(k)-xij.at(j).at(k));
        sum += pow(a, 2);
      }
      if (sqrt(sum) == floor(sqrt(sum))) ans++;
    }
  }
  cout << ans << endl;
}