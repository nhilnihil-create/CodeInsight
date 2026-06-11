#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int64_t A = -100000000000;
  vector<vector<int64_t>> memo(N, vector<int64_t>(2)); 
  for (int i = 0; i < N; i++) {
    int64_t X, L;
    cin >> X >> L;
    memo.at(i).at(0) = X + L;
    memo.at(i).at(1) = X - L;
    A = max(A, memo.at(i).at(1));
  }
  sort(memo.begin(), memo.end());
  int ans = 1;
  int64_t G = memo.at(0).at(0);
  for (int i = 0; i < N; i++) {
    if (memo.at(i).at(1) >= G) {
      G = memo.at(i).at(0);
      ans++;
    }
  }    
  cout << ans << endl;
}