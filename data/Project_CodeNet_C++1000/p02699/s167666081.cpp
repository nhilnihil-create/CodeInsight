#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll s, w;
  cin >> s >> w;
  if (s <= w) cout << "unsafe" << endl;
  else cout << "safe" << endl;
}