// #define _GLIBCXX_DEBUG

#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

#define int long long

using namespace std;

int N, K, C;
string S;

signed main() {
  cin >> N >> K >> C >> S;

  static int l[200002] = { };
  static int r[200002] = { };

  {
    int counter = 0;
    int prev = -1;
    for (int i = 0; i < N; i++) {
      if (S[i] == 'o' && (prev == -1 || prev + C < i)) {
        l[counter] = i;
        prev = i;
        counter++;
      }
    }
  }

  {
    int counter = K - 1;
    int prev = -1;
    for (int i = N - 1; i >= 0 && counter >= 0; i--) {
      if (S[i] == 'o' && (prev == -1 || prev - C > i)) {
        r[counter] = i;
        prev = i;
        counter--;
      }
    }
  }

  for (int i = 0; i < K; i++) {
    if (l[i] == r[i]) {
      cout << l[i] + 1 << endl;
    }
  }

  return 0;
}
