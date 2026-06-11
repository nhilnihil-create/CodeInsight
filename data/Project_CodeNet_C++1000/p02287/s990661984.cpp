#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  cin >> H;
  vector<int> heap(H + 1);

  for (size_t i = 0; i < H; i++) {
    cin >> heap[i + 1];
  }

  for (size_t i = 1; i < H + 1; i++) {
    auto node = heap[i];
    cout << "node " << i << ": key = " << node << ", ";
    if (i / 2 >= 1) {
      cout << "parent key = " << heap[i / 2] << ", ";
    }
    if (2 * i <= H) {
      cout << "left key = " << heap[2 * i] << ", ";
    }
    if (2 * i + 1 <= H) {
      cout << "right key = " << heap[2 * i + 1] << ", ";
    }

    cout << endl;
  }
}

