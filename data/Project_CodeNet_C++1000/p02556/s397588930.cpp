#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> u(N), v(N);
  int x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    u.at(i) = x - y;
    v.at(i) = x + y;
  }
  sort(u.begin(), u.end());
  sort(v.begin(), v.end());
  cout << max(u.at(N - 1) - u.at(0), v.at(N - 1) - v.at(0));
}
