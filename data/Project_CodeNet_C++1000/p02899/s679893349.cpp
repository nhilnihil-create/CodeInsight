#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(void) {

  int n;
  cin >> n;
  int ans[n];
  for(int i = 0; i < n; i++) {
    int b;
    cin >> b;
    ans[b - 1] = i + 1;
  }
  for(int i = 0; i < n - 1; i++) {
    cout << ans[i] << " ";
  }
  cout << ans[n - 1] << endl;

  return 0;
}
