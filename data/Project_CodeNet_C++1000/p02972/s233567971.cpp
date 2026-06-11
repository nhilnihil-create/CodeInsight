#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> q(N);
  vector<int> ans(N,0);
  int M = 0;
  for (int &e : q) cin >> e;
  for (int i = N; i > 0; i--) {
    int p = N/i;
    int sum = 0;
    for (int j = 2; j <= p; j++) sum += ans[i*j-1];
    if (sum % 2 != q[i-1]) {
      ans[i-1] = 1;
      M += 1;
    }
  }
  cout << M << endl;
  for (int i = 0; i < N; i++) {
    if (ans[i] == 1) {
      M -= 1;
      cout << i+1 << (M == 0 ? "\n" : " "); 
    }
  }
}