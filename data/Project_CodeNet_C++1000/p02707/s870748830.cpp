#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  rep(i, n) {
    if (i == 0) continue;
    int a;
    cin >> a;
    a--;
    cnt.at(a)++;
  }

  rep(i, n) cout << cnt.at(i) << endl;
}
