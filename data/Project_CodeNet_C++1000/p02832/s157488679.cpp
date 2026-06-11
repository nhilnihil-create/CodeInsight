#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> A(N);
  int k = 1;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (A.at(i) == k) {
      k++;
    }
    else {
      ans++;
    }
  }
  if (ans == N) {
    ans = -1;
  }
  cout << ans << endl;
}