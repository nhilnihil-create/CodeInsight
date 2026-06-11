#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a1,a2,a3;
  cin >> a1 >> a2 >> a3;
  if (a1 + a2 + a3 >= 22) cout << "bust" << endl;
  else cout << "win" << endl;
  return 0;
}
