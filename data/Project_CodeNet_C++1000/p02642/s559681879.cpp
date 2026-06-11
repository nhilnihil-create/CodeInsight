#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  vector<int> dp(1000001);
  for (int i = 1; i <= N; i++) {
    dp.at(A.at(i))++;
    if (dp.at(A.at(i)) == 1) {
      for (int j = A.at(i) * 2; j <= 1000000; j += A.at(i)) {
        dp.at(j)++;
      }
    }
  }
  int result = 0;
  for (int j : A) {
    if (dp.at(j) == 1) result++;
  }
  cout << result << endl;
  return 0;
}