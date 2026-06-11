#include <iostream>

using namespace std;

int main() {
  int N, K, R, S, P, ans{};
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  for (int i = 0; i != N; ++i) {
    if (i >= K && T[i] == T[i-K]) {
      T[i] = 'n';
      continue;
    }
    ans += T[i] == 'r' ? P : T[i] == 's' ? R : S;
  }
  cout << ans << endl;
}
