#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

bool IsPowerOfTwo(int x) {
  return x > 0 && (x & (x - 1)) == 0;
}

void PrintEdge(int v1, int v2) {
  cout << v1 << " " << v2 << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  if (IsPowerOfTwo(n)) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  PrintEdge(1, 2);
  PrintEdge(2, 3);
  PrintEdge(3, n + 1);
  PrintEdge(n + 1, n + 2);
  PrintEdge(n + 2, n + 3);
  for (int i = 4; i + 1 <= n; i += 2) {
    PrintEdge(1, i);
    PrintEdge(i, i + 1);
    PrintEdge(1, n + i + 1);
    PrintEdge(n + i + 1, n + i);
  }

  if (n % 2 == 0) {
    for (int i = 1; i <= n - 1; i++) {
      if ((n ^ 1 ^ i) < n) {
        int v1 = i;
        int v2 = n ^ i ^ 1;
        if (v1 == v2) continue;
        if (v1 % 2 == 1) v1 += n;
        if (v2 % 2 == 1) v2 += n;
        PrintEdge(n, v1);
        PrintEdge(v2, 2 * n);
        return 0;
      }
    }
  }
}
