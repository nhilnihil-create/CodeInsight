#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  S = '#' + S + '#';
  bool fail_A = false;
  for (int i = A; i + 1 <= C; i++) {
    if (S[i] == '#' && S[i + 1] == '#') {
      fail_A = true;
      break;
    }
  }
  bool fail_B = false;
  for (int i = B; i + 1 <= D; i++) {
    if (i < N - 1 && S[i] == '#' && S[i + 1] == '#') {
      fail_B = true;
      break;
    }
  }
  if (fail_A || fail_B) {
    cout << "No" << endl;
    return 0;
  }
  if (C < D) {
    cout << "Yes" << endl;
    return 0;
  }
  if (D < C) {
    bool fail = true;
    for (int i = B; i <= D; i++) {
      if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
        fail = false;
        break;
      }
    }
    if (fail) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}