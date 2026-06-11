#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
using namespace std;

const double eps = 1e-5;
template <typename T>
void print_vec(const vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

bool check(vector<int> &a, double len, int k) {
  int cnt = 0;
  for (auto ai: a) {
    if (ai <= len) continue;
    cnt += (ai + len - 1) / len - 1;
  }
  return cnt <= k;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int max_len = 0;
  for (auto &ai: a) {
    cin >> ai;
    max_len = max(max_len, ai);
  }

  int l = 0, r = max_len;
  while (r - l > 1) {
    int mid = (l + r)/ 2;
    if (check(a, mid, k)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << '\n';

  return 0;
}
