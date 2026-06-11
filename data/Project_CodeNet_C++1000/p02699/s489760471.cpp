#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  int s, w;
  cin >> s >> w;
  if (w >= s) {
    cout << "unsafe" << endl;
  } else {
    cout << "safe" << endl;
  }
  return 0;
}