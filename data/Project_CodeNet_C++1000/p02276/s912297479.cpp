#include <bits/stdc++.h>
using namespace std;

int mypartition(vector<int> &A, int p, int r) {
  int x = A[r], i = p - 1, tmp;
  for (int j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      tmp = A[j];
      A[j] = A[i];
      A[i] = tmp;
    }
  }

  tmp = A[++i];
  A[i] = A[r];
  A[r] = tmp;

  return i;
}
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < n; i++) {
    cin >> A.at(i);
  }

  int idx = mypartition(A, 0, n - 1);
  for (size_t i = 0; i < n; i++) {
    if (i == idx) {
      cout << '[' << A[i] << "] ";
    } else if (i == n - 1) {
      cout << A[i] << endl;
    } else {
      cout << A[i] << ' ';
    }
  }
}
