#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  string n;
  cin >> n;
  REP(i, n.size()) {
    if (n[i] == '7') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}