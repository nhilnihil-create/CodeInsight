#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int main() {
  int x, y;
  cin >> x >> y;
  int num_min = x*2;
  int num_max = x*4;
  if (num_min <= y && y <= num_max && y%2 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}