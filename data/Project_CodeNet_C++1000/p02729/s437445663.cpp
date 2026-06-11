#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i - 1;
  }
  for(int i = 1; i <= m; i++) {
    sum += i - 1;
  }
  cout << sum << endl;
  return 0;
}
