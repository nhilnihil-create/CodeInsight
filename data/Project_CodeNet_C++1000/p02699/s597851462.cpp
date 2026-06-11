#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int S, W;
  cin >> S >> W;

  if (S > W)
    cout << "safe" << endl;
  else
    cout << "unsafe" << endl;

  return 0;
}