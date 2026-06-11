#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0 ; i < (int)(n) ; ++i)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  queue<int> q;
  rep (i, N) {
    int H;
    cin >> H;

    q.push(H);
  }

  int current = q.front();
  q.pop();

  int max = current;

  bool result = true;
  while (!q.empty()) {
    int next = q.front();
    q.pop();

    if (next == current) {
      continue;
    }

    if (next < current) {
      int tmp = current - 1;

      if (next != tmp || tmp < max) {
        result = false;
        break;
      }

      current = tmp;
      max = tmp;
    } else {
      current = next;
    }
  }

  cout << (result ? "Yes" : "No") << '\n';

  return 0;
}