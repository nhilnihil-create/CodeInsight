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
  ll A, B, K;
  cin >> A >> B >> K;
  ll res = K - A;
  if (res >= 0) {
    A = 0;
    if (res >= B) B = 0;
    else B -= res;
  }
  else A -= K;
  cout << A << ' ' << B << endl;
  return 0;
}