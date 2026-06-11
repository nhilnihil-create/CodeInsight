/*input
4
20 11 9 24
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int A = 0;
  rep(i, n) {
    cin >> a[i];
    A ^= a[i];
  }
  rep(i, n) cout << (A^a[i]) << " ";
  cout << endl;
}