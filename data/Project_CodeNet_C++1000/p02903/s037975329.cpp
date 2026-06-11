#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int H, W, a, b;
  cin >> H >> W >> a >> b;

  for (int h = 0; h < H; ++ h) {
    for (int w = 0; w < W; ++w) {
      int cur = (h < b) ^ (w < a);
      cout << cur;
    }
    cout << endl;
  }

  return 0;
}
