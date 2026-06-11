#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;


int main() {
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  int cnt = 0;
  while (a >= b) {
    b *= 2;
    cnt++;
  }
  while (b >= c) {
    c *= 2;
    cnt++;
  }
  if (cnt <= k) cout << "Yes" << endl;
  else cout << "No" << endl;
}
