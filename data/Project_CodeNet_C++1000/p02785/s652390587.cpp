#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  long long S = 0;
  cin >> n >> k;
  vector<int> h(n);
  for(int i = 0;i < n;i++) cin >> h[i];
  sort(h.begin(), h.end());
  for(int i = 0;i < (n - k);i++) S += h[i];
  cout << S << endl;
}