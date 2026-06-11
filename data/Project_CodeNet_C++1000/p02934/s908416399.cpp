#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  double ans;
  int64_t sum = 0;
  vector<int> num(n, 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += 1e10 / a[i];
  }

  ans = 1e10 / sum;

  printf("%.10f", ans);

}