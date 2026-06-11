#include <iostream>
#include <vector>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int> > x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i]; j++) {
      int temp;
      cin >> temp;
      temp--;
      x[i].push_back(temp);
      cin >> temp;
      y[i].push_back(temp);
    }
  }
  int ans = 0;
  for (int z = 1; z < 1 << n; z++) {
    bool check = true;
    int num = 0;
    for (int i = 0; i < n; i++) {
      if (z >> i & 1) {
        num++;
        for (int j = 0; j < a[i]; j++) {
          if (((z >> x[i][j]) & 1) != y[i][j]) check = false;
        }
      }
    }
    if (check && ans < num) {
      ans = num;
    }
  }
  cout << ans << endl;
  return 0;
}