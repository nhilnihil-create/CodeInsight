#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int K, X; cin >> K >> X;
  if (500 * K >= X) cout << "Yes" << endl;
  else              cout << "No" << endl;
}
