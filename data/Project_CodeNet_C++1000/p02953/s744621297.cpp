#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;

int main() {
  long long n;
  cin >> n;
  long long h[1000001];

  for (long long i = 0; i < n; i++) {
    cin >> h[i];
  }

  int pre = -999;
  for (long long i = 0; i < n; i++) {
    if (pre <= h[i]-1) {
      pre = h[i]-1;
    } else if (pre <= h[i]) {
      pre = h[i];
    } else {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}