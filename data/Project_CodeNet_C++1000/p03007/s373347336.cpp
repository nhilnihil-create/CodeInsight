#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += abs(A[i]);
  }

  sort(A.begin(), A.end());
  if (A[0] >= 0) {
    cout << sum - A[0] * 2 << endl;

    int x = A[0];
    for (int i = 1; i < n; i++) {
      if (i == n - 1) {
        cout << A[i] << " " << x << endl;
      }
      else {
        cout << x << " " << A[i] << endl;
      }
      x -= A[i];
    }
  }
  else if (A[n - 1] <= 0) {
    cout << sum + A[n - 1] * 2 << endl;

    int x = A[n - 1];
    for (int i = 0; i < n - 1; i++) {
      cout << x << " " << A[i] << endl;
      x -= A[i];
    }
  }
  else {
    cout << sum << endl;

    int x = A[0];
    bool change = false;
    for (int i = n - 1; i > 0; i--) {
      if (A[i - 1] >= 0) {
        cout << x << " " << A[i] << endl;
        x -= A[i];
      }
      else {
        if (change) {
          cout << x << " " << A[i] << endl;
          x -= A[i];
        }
        else {
          cout << A[i] << " " << x << endl;
          x = A[i] - x;
          change = true;
        }
      }
    }
  }

  return 0;
}