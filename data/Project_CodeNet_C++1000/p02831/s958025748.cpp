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

int gcd(int x, int y) {
  if (x%y == 0) return y;
  return gcd(y, x%y);
}

int main() {
  ll A, B;
  cin >> A >> B;
  ll lcm = A * B / gcd(A,B);
  cout << lcm << endl;
  return 0;
}