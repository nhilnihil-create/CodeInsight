#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int X, Y, ans = 0;
  cin >> X >> Y;
  if (X==3) ans += 100000;
  else if (X==2) ans += 200000;
  else if (X==1) ans += 300000;
  if (Y==3) ans += 100000;
  else if (Y==2) ans += 200000;
  else if (Y==1) ans += 300000;
  if (X==1&&Y==1) ans += 400000;
  cout << ans << endl;
}