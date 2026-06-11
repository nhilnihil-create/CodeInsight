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
  int N;
  cin >> N;
  vector<float> A;
  rep(i, N) {
    float a;
    cin >> a;
    A.push_back(a);
  }
  float ans = 0;
  rep(i, N) { ans += 1 / A.at(i); }
  cout << 1.0 / ans << endl;
}
