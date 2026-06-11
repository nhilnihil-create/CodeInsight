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
  vector<int> a(n);
  vector<int> b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }

  sort(b.begin(), b.end(), greater<int>());

  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    if (a[i] == b[0]) {
      cout << b[1] << endl;
    } else {
      cout << b[0] << endl;
    }
  }
}