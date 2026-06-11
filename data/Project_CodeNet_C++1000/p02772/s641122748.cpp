#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int a[10001];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      if (a[i] % 3 == 0 || a[i] % 5 == 0) {
        continue;
      } else {
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }

  cout << "APPROVED" << endl;
}