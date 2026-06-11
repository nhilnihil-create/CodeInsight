#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int64_t sum = 1;
  cin >> n;
  vector<int64_t> a(n);
  for (int i = 0; i<n; i++) {
    cin >> a.at(i);
  }
  for (int i = 0; i<n; i++) {
    if (a.at(i) == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i<n; i++) {
    if (a.at(i) <= 1000000000000000000/sum) {
      sum *= a.at(i);
    }
    else {
      cout << "-1" << endl;
      return 0;
    }
  }
  cout << sum << endl;
}