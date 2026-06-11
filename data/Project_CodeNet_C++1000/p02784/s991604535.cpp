#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int h, n;
  cin >> h >> n;
  ll sum = 0;
  rep(i, n) {
    int a;
    cin >> a;
    sum += a;
  }
  if (h <= sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
