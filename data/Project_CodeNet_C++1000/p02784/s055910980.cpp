#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int h, n, a = 0;
  cin >> h >> n;
  rep(i, n) {
    int x;
    cin >> x;
    a += x;
  }
  if (a < h) cout << "No" << endl;
  else cout << "Yes" << endl;
}