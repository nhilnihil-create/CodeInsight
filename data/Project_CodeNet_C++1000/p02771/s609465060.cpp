#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b, c;
  cin >> a >> b >> c;
  bool isPoor = false;
  if (a == b && b != c) isPoor = true;
  if (b == c && c != a) isPoor = true;
  if (c == a && a != b) isPoor = true;

  if (isPoor) cout << "Yes" << endl;
  else cout << "No" << endl;

}
