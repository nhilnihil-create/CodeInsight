#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int N, X, Y;
  cin >> N;
  cin >> X;
  cin >> Y;
  
  vector <int> ans(N, 0);
  
  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      int l = min(j - i, abs(i - X) + 1 + abs(j - Y));
      ans[l]++;
    }
  }
  
  for (int i = 1; i < N; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}