#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> A(N - 1), ans(N);
  for (int i = 0; i < N - 1; i++) {
    cin >> A.at(i);
    int a = A.at(i) - 1;
    ans.at(a) = ans.at(a) + 1;
  }
  for (int i = 0; i < N; i++) {
    cout << ans.at(i) << endl;
  }
}