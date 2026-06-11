#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  int A, B;
  cin >> A >> B;

  vector<bool> ans(3, true);
  ans[A - 1] = false;
  ans[B - 1] = false;

  rep(i, 3) {
    if (ans[i]) cout << i + 1 << endl;
  }
}