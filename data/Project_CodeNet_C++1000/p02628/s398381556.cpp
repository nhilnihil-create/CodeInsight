#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> arr{};
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    arr.push_back(p);
  }
  sort(arr.begin(), arr.end());
  int sum = accumulate(arr.begin(), arr.begin()+k, 0);
  cout << sum << endl;
}
