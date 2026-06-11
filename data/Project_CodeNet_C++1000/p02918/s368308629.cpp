#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  int count = 0;

  for (int i = 0; i < N - 1; i++) {
    if (S[i] == S[i + 1]) {
      count++;
    }
  }

  int answer = min(count + 2 * K, N - 1);
  cout << answer << endl;

  return 0;
}