#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N, D; cin >> N >> D;
  int cnt = 0;
  int x = 0;
  while (x < N) {
    ++cnt;
    x += 2 * D + 1;
  }
  cout << cnt << endl;
}
