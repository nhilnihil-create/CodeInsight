#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  double total = 0.0;
  for(int i = 0; i < n; i++) {
    double x;
    cin >> x;
    total += 1.0 / x;
  }
  total = 1.0 / total;
  cout << setprecision(16) << total << endl;
}
