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
  string S;
  cin >> S;

  bool ans = true;
  rep(i, S.size()) {
    if (S[i] == 'L' && i % 2 == 0) ans = false;
    if (S[i] == 'R' && i % 2 == 1) ans = false;
  }

  if (ans == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
