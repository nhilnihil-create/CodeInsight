#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
using pi = pair<int, int>;
 
int main() {
  int n; cin >> n;
  vector <int> as(n, 0);
  for (auto& a : as) cin >> a;
  sort(as.begin(), as.end());
  reverse(as.begin(), as.end());
  long long sum = as[0];
  if (n <= 1) { cout << 0 << endl; return 0; }
  if (n <= 2) { cout << sum << endl; return 0; }
  for (int i = 2; i < n; i++) {
    sum += as[i / 2];
  }
  cout << sum << endl;
}