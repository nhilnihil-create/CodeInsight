#include <iostream>

using namespace std;

int m[101];

int main() {
  int N, K;
  cin >> N >> K;

  for (int i = 0; i < K; i++) {
    int d;
    cin >> d;
    for (int j = 0; j < d; j++) {
      int a;
      cin >> a;
      m[a]++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (!m[i]) {
      ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}
