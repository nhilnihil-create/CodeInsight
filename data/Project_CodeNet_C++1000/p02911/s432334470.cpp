#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<int> memo(N, 0);
  for (int i = 0; i < Q; i++) {
    int A;
    cin >> A;
    memo.at(A - 1)++;
  }
  for (int i = 0; i < N; i++) {
    if (K - Q + memo.at(i) > 0) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}