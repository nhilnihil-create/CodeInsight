#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdint>

using namespace std;

int main() {
  while (true) {
    int h, w;
    cin >> h >> w;
    if (!h && !w) break;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        cout << '#';
      }
      cout << endl;
    }
    cout << endl;
  }
}