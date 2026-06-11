#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  string S;
  cin >> S;
  int res = 0;
  int left = 0, right = N - 1;
  while (left < right) {
    while (left < N && S[left] == 'R') {
      left++;
    }
    while (right > -1 && S[right] == 'W') {
      right--;
    }
    if (left >= right) break;
    left++, right--;
    res++;
  }
  cout << res << '\n';
  return 0;
}
