#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double x, ans=0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> x;
    ans = ans + 1/x;
  }
  
  cout << fixed;
  cout << setprecision(6) << 1 / ans << endl;;
}