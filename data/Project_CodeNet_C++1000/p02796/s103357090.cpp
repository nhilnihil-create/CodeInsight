#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int,int>> range(N);
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    range[i].first = a+b;
    range[i].second = a-b;
  }
  
  sort(range.begin(), range.end());
  int l = range[0].first;
  int ans = 1;
  for (int i = 1; i < N; i++) {
    if (l <= range[i].second) {
      ans += 1;
      l = range[i].first;
    }
  }
  cout << ans << endl;
}