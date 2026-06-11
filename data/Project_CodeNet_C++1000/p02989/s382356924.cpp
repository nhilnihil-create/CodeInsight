#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> ds(n);
  for (int &d : ds) cin >> d;

  sort(ds.begin(), ds.end());
  int result = ds[n / 2] - ds[n / 2 - 1];
  cout << result << endl;
  return 0;
}