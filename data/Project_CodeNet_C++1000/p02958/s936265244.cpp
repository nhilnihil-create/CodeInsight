#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main(void) {
  int n;
  cin >> n;
  int p[n];
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for(int i = 0; i < n - 1; i++) {
    if(p[i] != i + 1) {
      swap(p[i], p[p[i] - 1]);
      break;
    }
  }
  for(int i = 0; i < n - 1; i++) {
    if(p[i] > p[i + 1]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}