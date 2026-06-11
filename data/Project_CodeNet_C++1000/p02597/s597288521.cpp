#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<char> C(N);
  for (int i = 0; i < N; i++) cin >> C.at(i);
  
  int r = 0;
  for (int i = 0; i < N; i++) {
    if (C.at(i) == 'R') r++;
  }
  int ans = 0;
  for (int i = 0; i < r; i++) {
    if (C.at(i) == 'W') ans++;
  }
  cout << ans << endl;
}