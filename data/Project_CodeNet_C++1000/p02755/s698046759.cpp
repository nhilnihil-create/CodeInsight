#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B;
  cin >> A >> B;
  if (max(100 * A, 80 * B) < min(80 * (B+1), 100 * (A+1))) cout << max(int(12.5 * A + 0.5), 10 * B) << endl;
  else cout << -1 << endl;
  return 0;
}