#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  vector<int> ans(N);
  bool memo = true;
  if (N == 1 && M == 0) {
    cout << 0 << endl;
    memo = false;
  }
  if (N == 1 && M == 1) {
    int a, b;
    cin >> a >> b;
    if (a == 1 && b == 0) {
      cout << 0 << endl;
      memo = false;
    }
  }
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    if (b == 0) {
      ans.at(a - 1) = 100;
    }
    else if (ans.at(a - 1) == 0) {
      ans.at(a - 1) = b;
    }
    else if (b != ans.at(a - 1)) {
      cout << "-1" << endl;
      memo = false;
      break;
    }
  }
  if (ans.at(0) == 0) {
    ans.at(0) = 1;
  }
  for (int i = 0; i < N; i++) {  
    if (ans.at(i) == 100) {
      ans.at(i) = 0;
    }
  }
  if (memo == true && ans.at(0) == 0) {
    cout << "-1" << endl;
    memo == false;
  }
  else if (memo == true) {
    for (int i = 0; i < N; i++) {
    cout << ans.at(i); 
    }
  }
}