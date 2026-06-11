#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) cin >> a[i];
  int res = 0;
  for (int i = 0; i < N;) {
    int j = i + 1;
    while (j < N && a[j] <= a[j-1]) ++j;
    res = max(res, j - i - 1);
    i = j;
  }
  cout << res << endl;
}