#include<bits/stdc++.h>
using namespace std;

long long solve(long long h) {
  if (h == 1) {
    return 1;
  }
  return  2 * solve(h / 2) + 1;
}



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long h;
  cin >> h;
  cout << solve(h) << '\n';
  return 0;
}

