#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;

int main() {
  int N, L;
  cin >> N >> L;

  int sum = 0;
  int min_taste = INF;
  for (int i = 0; i < N; ++i) {
    sum += L + i;
    min_taste = min(min_taste, max(L + i, min(L + N - 1, 0)));
  }

  cout << sum - min_taste << endl;
  return 0;
}
