#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> u;
  for(int i = 0; i < n; i++) {
    int ui;
    cin >> ui;
    u.push_back(ui);
  }
  sort(u.begin(), u.end());
  long double ans = u[0];
  for(int i = 1; i < n; i++) {
    ans = (ans + u[i]) / 2;
  }
  cout << ans << endl;

  return 0;
}
