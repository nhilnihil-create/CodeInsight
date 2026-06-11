#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> ar(n);

  for (auto &a : ar) {
    cin >> a;
  }

  sort(ar.begin(), ar.end());
  int res = 0;
  for (int i = 0; i < k; i++) {
    res = res + ar[i];
  }

  cout << res << endl;



}