#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  if(k!=1) cout << n-k << endl;
  else cout << 0 << endl;
  return 0;
}