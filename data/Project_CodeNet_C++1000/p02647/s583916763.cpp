#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define INF (1e9)

int main() {
  int N, K;
  cin >> N >> K;
  vi A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  while (K--) {
    vi B(N + 1);
    for (int i = 0; i < N; i++) {
      B[max(0, i - A[i])]++;
      B[min(N, i + A[i] + 1)]--;
    }
    int s = 0;
    bool f = true;
    for (int i = 0; i < N; i++) {
      s += B[i];
      A[i] = s;
      f &= s == N;
    }
    if (f) break;
  }

  for (int i = 0; i < N; i++) {
    cout << A[i] << ' ';
  }
  cout << endl;
}
