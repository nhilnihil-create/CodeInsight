#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll X, yen;
  cin >> X;
  ll year = 0;
  yen = 100;
  while (yen / X < 1) {
    yen += yen / 100;
    year++;
  }
  cout << year << endl;
  return 0;
}