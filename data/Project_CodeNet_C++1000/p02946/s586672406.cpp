#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int main() {
  int K, X;
  cin >> K >> X;

  for (auto i = max(X-K+1,-1000000); i <= min(X+K-1,1000000); ++i) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
