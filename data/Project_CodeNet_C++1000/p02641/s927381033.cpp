#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, n;
  cin >> x >> n;
  unordered_set<int> hashset;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    hashset.insert(p);
  }
  int min_diff = 100;
  int min_val = 100;
  for (int val = 101; val >= 0; val--) {
    if (hashset.find(val) == hashset.end()) {
     int diff = abs(x - val);
     if (diff <= min_diff) {
         min_diff = diff;
         min_val = val;
     }
    }
  }
  cout << min_val << endl;
}