#include<bits/stdc++.h>
using namespace std;
bool solve() {
  long x1, v1, x2, v2; cin >> x1 >> v1 >> x2 >> v2;
  if (v1 <= v2) return false;
  long X = abs(x1 - x2);
  long V = v1 - v2;
  long T; cin >> T;
  return X <= V * T;
}
int main() {
  if (solve()) cout << "YES" << endl;
  else cout << "NO" << endl;
}