#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

float metric(vector<int>& a, vector<int>& b) {
  float sum = 0;

  rep(i, a.size()) { sum += (a[i] - b[i]) * (a[i] - b[i]); }
  return sqrt(sum);
}

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  rep(i, N) cin >> p[i];
  int count = 0;
  for (int i = 1; i < N - 1; i++) {
    int min_a = min(p[i + 1], min(p[i], p[i - 1]));

    int max_a = max(p[i + 1], max(p[i], p[i - 1]));

    if ((min_a != p[i]) && (max_a != p[i])) count++;
  }
  cout << count << endl;
}
