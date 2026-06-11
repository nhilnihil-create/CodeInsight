#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

i64 calc(i64 K) {
  if (K <= 9) return K;
  deque<i64> q;
  i64 v;
  for (i64 i = 1; i <= 9; i++) {
    q.push_back(i); K--;
  }
  while (true) {
    v = q.front();
    q.pop_front();
    if (q.empty()) break;
    i64 w = v % 10;
    if (w >= 1 && K > 0) {
      q.push_back(v * 10 + (w - 1)); K--;
    }
    if (K > 0) {
      q.push_back(v * 10 + w); K--;
    }
    if (w <= 8 && K > 0) {
      q.push_back(v * 10 + (w + 1)); K--;
    }
  }
  return v;
}

int main() {
  i64 K, v;
  cin >> K;
  v = calc(K);
  cout << v << endl;
  return 0;
}