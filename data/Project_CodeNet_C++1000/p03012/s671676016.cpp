#include <math.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int sum_(vector<int> v, int start, int end) {
  int num = 0;
  for (int i = start; i < end; i++) {
    num += v[i];
  }

  return num;
}

int main() {
  int N;
  cin >> N;

  vector<int> W;

  rep(i, N) {
    int a;
    cin >> a;
    W.push_back(a);
  }

  int ans = 100;
  rep(i, N) {
    int b_1 = accumulate(W.begin(), W.end() - (N - i), 0);
    int b_2 = accumulate(W.begin() + i, W.end(), 0);
    int ans_a = b_1 - b_2;
    ans = min(ans, abs(ans_a));
  }
  cout << ans << endl;
}
