#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main() {
  ll h,n;
  cin >> h >> n;
  ll total = 0;
  rep(i,n) {
    int x;
    cin >> x;
    total += x;
  }
  if (h <= total) cout << "Yes" << endl;
  else cout << "No" << endl;
}
