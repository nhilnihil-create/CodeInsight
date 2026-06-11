#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int A, B; cin >> A >> B;
  A -= 2 * B;
  cout << max(0, A) << endl;
}
