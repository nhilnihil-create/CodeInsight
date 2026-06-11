#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N, x, y=0;
  string ans = "No";
  cin >> H >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> x;
    y += x;
  }
  
  if (H <= y) ans = "Yes";

  cout << ans << endl;;
}