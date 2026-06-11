#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  double sum = 0.000000;
  for (int i = 0; i < N; i++) {
    if ((i + 1) % 2 != 0) {
      sum = sum + 1.000000;
    }
  }
  
  double ans = 0.000000;
  ans = sum / N;
  cout << ans << endl;
}
