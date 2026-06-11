#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a1,a2,a3;
  cin >> a1 >> a2 >> a3;

  if((a1+a2+a3) >= 22) {
    cout << "bust" << endl;
  }

  else {
    cout << "win" << endl;
  }
  return 0;
}
