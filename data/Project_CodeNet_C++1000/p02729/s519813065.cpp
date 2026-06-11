#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n, m;
  cin >> n >> m;
  int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
  cout << ans;
}
