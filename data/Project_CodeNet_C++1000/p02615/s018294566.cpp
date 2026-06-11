#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long S = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0;i < n;i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end(), greater<>());
  for(int i = 0;i < n - 1;i++) {
    S += v[(int)((i + 1) / 2)];
  }
  cout << S << endl;
}