#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

istream& operator>>(istream& in, vector<int>& a) {
  rep(i, 0, a.size()) in >> a[i];
  return in;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  cin >> a;
  int s = accumulate(a.begin(), a.end(), 0);
  sort(a.rbegin(), a.rend());
  cout << (a[m - 1] * 4 * m < s ? "No" : "Yes");
  return 0;
}
