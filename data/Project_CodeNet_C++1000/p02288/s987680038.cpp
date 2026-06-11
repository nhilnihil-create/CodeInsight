#include <bits/stdc++.h>
using namespace std;

void maxHeapify(vector<int> &heap, int i) {
  auto e = heap[i];
  int left = 2 * (i + 1) - 1, right = 2 * (i + 1), larger = i;
  if (right < heap.size()) {
    larger = heap[left] > heap[right] ? left : right;
  } else if (left < heap.size() ) {
    larger = left;
  }
  if (heap[larger] > e) {
    heap[i] = heap[larger];
    heap[larger] = e;
    maxHeapify(heap, larger);
  }
  return;
}
int main() {
  int H;
  cin >> H;
  vector<int> heap(H);
  for (size_t i = 0; i < H; i++) {
    cin >> heap[i];
  }

  for (int i = H / 2 - 1; i >= 0 ; i--) {
    maxHeapify(heap, i);
  }

  for (auto &&e : heap) {
    cout << ' ' << e;
  }

  cout << endl;
}

