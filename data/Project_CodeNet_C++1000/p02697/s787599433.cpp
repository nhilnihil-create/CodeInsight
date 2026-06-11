#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  bool f = N % 2 == 0;
  for (int i = 0, l = 1, r = N; i < M; i++, l++, r--) {
    if (r - l <= N / 2 && f) {
      r--;
      f = false;
    }
    cout << l << " " << r << endl;
  }
}
