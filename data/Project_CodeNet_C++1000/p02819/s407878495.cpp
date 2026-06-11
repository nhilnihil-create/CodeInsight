#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int X;
  cin >> X;
  vector<int> A(100020);
  A[0] = 1;
  A[1] = 1;
  for (int i = 2; i <= 100010; ++i) {
    if (A[i] > 0) continue;
    else {
      for (int j = 2 * i; j <= 100010; j += i) {
        A[j] += 1;
      }
    }
  }
  for (int i = X; i <= 100010; ++i) {
    if (A[i] == 0) {
      cout << i << endl;
      return 0;
    }
  }
  return 1;
}