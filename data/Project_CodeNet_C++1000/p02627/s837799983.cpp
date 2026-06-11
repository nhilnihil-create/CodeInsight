/*input
z
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  char c;
  cin >> c;
  if ('A' <= c && c <= 'Z') cout << 'A' << endl;
  else cout << 'a' << endl;
}