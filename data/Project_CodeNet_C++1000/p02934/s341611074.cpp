#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  double memo = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    memo += (1.0 / A.at(i));
  }
  double ans = 1.0 / memo;
  cout << fixed << setprecision(16);
  cout << ans << endl;
}
  