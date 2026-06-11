#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a==b) {
    if (a==c) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  else if (a==c) {
    if (b==c) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  else if (b==c) {
    if (a==b) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  else cout << "No" << endl;
  return 0;
}