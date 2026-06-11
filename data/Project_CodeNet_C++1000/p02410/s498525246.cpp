#include <iostream>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int a[m][n] = {};
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }

  int b[n];
  for(int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  int sigma[m] = {};
  for(int i = 0; i < m; ++i) {
    for(int j = 0; j < n; ++j) {
      sigma[i] += a[i][j] * b[j];
    }
  }

  for(int i = 0; i < m; ++i) {
    cout << sigma[i] << endl;
  }
}