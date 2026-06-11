#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int x;
  cin >> x;
  int ans;
  rep(i,8) if(400 + 200 * i <= x && x <= 599 + 200 * i) cout << 8 - i << endl;
}