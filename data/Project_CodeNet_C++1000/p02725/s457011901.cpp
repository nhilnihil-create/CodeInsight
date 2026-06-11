#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K, N;
  cin >> K >> N;
  int prev, next, first;
  cin >> first;
  next = first;
  int m = 0;
  rep(i, N - 1) {
    prev = next;
    cin >> next;
    m = max(m, next - prev);
  }
  m = max(m, (K + first - next));
  cout << K - m << endl;
}
