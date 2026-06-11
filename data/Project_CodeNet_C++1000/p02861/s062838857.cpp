#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> indexs(N);
  int xs[N], ys[N];
  for (int i = 0; i < N; i++) {
    indexs[i] = i;
    cin >> xs[i] >> ys[i];
  }
  double sum = 0.0;
  ll count = 0;
  do {
    for (int i = 1; i < N; i++) {
      double dx = xs[indexs[i - 1]] - xs[indexs[i]];
      double dy = ys[indexs[i - 1]] - ys[indexs[i]];
      sum += sqrt((dx * dx) + (dy * dy));
    }
    count++;
  } while (next_permutation(indexs.begin(), indexs.end()));
  double ans = sum / (ll)count;
  printf("%lf\n", ans);
  return 0;
}