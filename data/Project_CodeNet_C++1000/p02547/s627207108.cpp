#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  int N; cin >> N;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int d1, d2; cin >> d1 >> d2;
    if (d1 == d2) ++cnt;
    else          cnt = 0;

    if (cnt >= 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
