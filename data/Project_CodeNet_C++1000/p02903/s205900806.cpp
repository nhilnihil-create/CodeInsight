#include <iostream>

using namespace std;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  for (int h = 0; h != H; ++h) {
    for (int w = 0; w != W; ++w) {
      cout << ((w < A) ^ (h < B));
    }
    cout << endl;
  }
}
