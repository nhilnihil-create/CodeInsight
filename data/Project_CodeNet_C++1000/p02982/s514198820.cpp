#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int distance2(vector<int> a, vector<int> b) {
  int sum = 0;
  for (int i = 0; i < static_cast<int>(a.size()); ++i)
    sum += pow(a[i] - b[i], 2);
  return sum;
}

int main() {
  int n, d;
  cin >> n >> d;

  vector<vector<int>> vec(n, vector<int>(d));
  for (auto &v : vec)
    for (auto &a : v)
      cin >> a;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int d2 = distance2(vec[i], vec[j]);
      if (pow(int(sqrt(d2)), 2) == d2)
        ++cnt;
    }
  }

  cout << cnt << endl;
}