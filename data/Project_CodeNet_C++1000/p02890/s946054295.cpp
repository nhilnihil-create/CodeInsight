#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}

template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> xs(n);
  vector<int> x_to_count(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
    x_to_count[xs[i]]++;
  }

  vector<int> count_to_sum(n + 1);
  for (int x = 1; x <= n; x++) {
    for (int c = 1; c <= x_to_count[x]; c++) {
      count_to_sum[c]++;
    }
  }

  if (DEBUG) cout << "count_to_sum: " << count_to_sum << endl;

  vector<int> k_to_count(n + 1, 0);
  int current_sum = 0;
  for (int c = 1; c <= n; c++) {
    current_sum += count_to_sum[c];
    // cout << current_sum / c << endl;
    k_to_count[current_sum / c] = c;
  }

  for (int k = n - 1; k >= 1; k--) {
    UpdateMax(k_to_count[k], k_to_count[k + 1]);
  }

  int current_output = n;
  for (int k = 1; k <= n; k++) {
    cout << k_to_count[k] << "\n";
  }
}