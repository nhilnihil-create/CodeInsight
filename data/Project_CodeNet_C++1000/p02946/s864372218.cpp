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
  int K, X;
  cin >> K >> X;

  int S = K - 1;

  rep(i, 2 * K - 1) { cout << X - S + i << endl; }
}
