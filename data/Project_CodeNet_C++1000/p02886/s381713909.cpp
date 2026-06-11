#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i, n) cin >> d.at(i);
  int sum = 0;
  rep(i, n) {
    if(i == n - 1) break;
    int cmp = d.at(i);
    for(int j = i + 1; j < n; j++) {
      sum += cmp * d.at(j);
    }
  }
  cout << sum << endl;
  return 0;
}