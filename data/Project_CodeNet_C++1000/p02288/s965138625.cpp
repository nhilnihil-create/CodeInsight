#include <bits/stdc++.h>
using namespace std;

int H;
vector<int> A;

void MaxHeapi(int i) {
  int l = 2 * i, r = 2 * i + 1, largest;
  if (l <= H && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if (r <= H && A[r] > A[largest])
    largest = r;

  if (largest != i) {
    swap(A[i], A[largest]);
    MaxHeapi(largest);
  }
}

void BuildMaxHeap() {
  for (int i = H / 2; i >= 1; --i)
    MaxHeapi(i);
}

int main() {
  cin >> H;
  A.resize(H + 1);
  for (int i = 1; i <= H; ++i)
    cin >> A[i];

  BuildMaxHeap();

  for (int i = 1; i <= H; ++i)
    cout << ' ' << A[i];
    cout << endl;
}

