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
  int N, L;
  cin >> N >> L;

  int last = L + N - 1;

  int a = 0;
  if (last <= 0)
    a = last;
  else if (L >= 0)
    a = L;
  else
    a = 0;
  int ans = (last + L) * (last - L + 1) / 2 - a;
  cout << ans << endl;
}
