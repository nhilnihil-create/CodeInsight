#include <bits/stdc++.h>
using namespace std;
 
int main(){ 
  int N, K;
  cin >> N >> K;
  vector<int> memo(N);
  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    vector<int> A(d);
    for (int j = 0; j < d; j++) {
      cin >> A.at(j);
      memo.at(A.at(j) - 1) = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (memo.at(i) == 0) {
      ans++;
    }
  }
  cout << ans << endl;
 
}