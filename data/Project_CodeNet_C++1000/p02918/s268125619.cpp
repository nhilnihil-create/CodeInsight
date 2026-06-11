#include <iostream>

using namespace std;

int main() {
  int N, K, u{}, p{};
  string S;
  cin >> N >> K >> S;
  if (S[0] == 'L') ++u;
  if (S[N - 1] == 'R') ++u;
  for (int i = 1; i != N; ++i)
    if (S[i - 1] == 'R' && S[i] == 'L') ++p;
  if (K <= p) {
    cout << N - 2 * (p - K) - u << endl;
  } else {
    cout << N - 1 << endl;
  }
}
