#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int n, m;
  cin >> n >> m;
  int x = 0;
  for (int i = 0; i < m; i++) {
    int a;
    cin >> a;
    x += a;
  }
  if (n-x < 0) cout << -1 << endl;
  else cout << n-x << endl;
  return 0;
}