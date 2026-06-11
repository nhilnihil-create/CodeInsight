#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans;
  rep(i, max(a, b)) {
    cout << min(a, b);
  }
  cout << endl;
}
