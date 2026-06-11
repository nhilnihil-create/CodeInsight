#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int count = 0;
  for (int i = 0; i < 1000; ++i) {
    int c[3] = {i / 100, (i / 10) % 10, i % 10};
    int f = 0;
    for (int j = 0; j < N; ++j) {
      if (S[j] == ('0' + c[f])) {
        ++f;
      }
      if (f == 3) {
        break;
      }
    }
    if (f == 3) {
      ++count;
    }
  }
  cout << count << endl;
  return 0;
}