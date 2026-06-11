#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <deque>
using namespace std;
int main() {
  int n;
  int w_count = 0,r_count = 0, cost = 0;
  string c;
  cin >> n >> c;
  for (int i=0; i<n; i++) if (c[i] == 'R') r_count++;
  cost = r_count;
  for (int i=0; i<n; i++) {
    if (c[i] == 'W') w_count++;
    else r_count--;
    cost = min(max(r_count, w_count), cost);
  }
  cout << cost << endl;
}