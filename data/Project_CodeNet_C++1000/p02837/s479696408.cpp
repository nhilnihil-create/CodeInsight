#include <math.h>
#include <stdio.h>
#include <bitset>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  int xs[15][15] = {{}};
  int ys[15][15] = {{}};
  int cs[15] = {};
  int As[15] = {};
  unsigned int max = 0;
  for (int i = 0; i < N; i++) {
    cin >> As[i];
    for (int j = 0; j < As[i]; j++) {
      cin >> xs[i][j] >> ys[i][j];
    }
  }
  for (int bit = 0; bit < (1 << N); bit++) {
    for (int i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        cs[i] = 1;
      } else {
        cs[i] = 0;
      }
    }
    bool check = true;
    for (int i = 0; i < N; i++) {
      if (cs[i] == 0) {
        continue;
      }
      for (int j = 0; j < As[i]; j++) {
        if (cs[xs[i][j] - 1] != ys[i][j]) {
          check = false;
        }
      }
    }
    if (check) {
      int count = 0;
      for (int i = 0; i < N; i++) {
        if (cs[i] != 0) {
          count++;
        }
      }
      if (max <= count) {
        max = count;
      }
    }
  }
  cout << max << endl;
}