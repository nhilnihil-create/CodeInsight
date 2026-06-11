#include <math.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define PI 3.14159265358979323846264338327950L
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))

int main() {
  int N, K;
  vector<int> h;

  cin >> N >> K;
  rep(i, N) {
    int a;
    cin >> a;
    h.push_back(a);
  }

  int sum = 0;
  rep(i, N) {
    if (h.at(i) >= K) sum++;
  }
  cout << sum << endl;
}
