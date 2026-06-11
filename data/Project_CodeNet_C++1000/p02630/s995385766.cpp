#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(100000 + 1, 0);
  ll sum = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    sum += a;
    A[a]++;
  }
  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int b, c;
    cin >> b >> c;
    sum += c * A[b] - b * A[b];
    A[c] += A[b];
    A[b] = 0;
    cout << sum << '\n';
  }
}
