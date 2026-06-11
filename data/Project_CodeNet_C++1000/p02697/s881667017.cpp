#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  int a = 1, b = M + 2;
  for (int i = M; i > 0; i--) {
    cout << a << ' ' << a + i << '\n';
    a++;
    swap(a, b);
  }
  return 0;
}
