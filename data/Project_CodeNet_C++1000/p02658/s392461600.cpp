#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long> a(n);
  for (auto& x : a) cin >> x;
  sort(a.begin(), a.end());
  
  long seki = 1;
  for (long x : a) {
    if (x > 0 && seki > long(1e18) / x) {
      return cout << -1 << endl, 0;
    }
    seki *= x;
  }
  cout << seki << endl;
}