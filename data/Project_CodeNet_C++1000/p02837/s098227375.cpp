#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> a;
int x[15][15];
int y[15][15];

bool judge(int bit) {
  for (int i = 0; i < n; i++) {
    if (!(bit & (1 << i))) {
      continue;
    }

    for (int j = 0; j < a[i]; j++) {
      if (y[i][j] == 1 && !(bit & (1 << x[i][j]))) {
        return false;
      }

      if (y[i][j] == 0 && (bit & (1 << x[i][j]))) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> n;
  a.resize(n);

  for (int i = 0; i< n; i++) {
    cin >> a[i];

    for (int j = 0; j < a[i]; j++) {
      cin >> x[i][j] >> y[i][j];
      x[i][j]--;
    }
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << n); bit++) {
    if (judge(bit)) {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) {
          count++;
        }
      }
      ans = max(ans, count);
    }
  }

  cout << ans << endl;
}