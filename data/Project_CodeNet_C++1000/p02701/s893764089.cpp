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
  int n;
  cin >> n;
  map<string, bool> x;
  REP(i, n) {
    string s;
    cin >> s;
    x[s] = true;
  }
  cout << x.size() << endl;
  return 0;
}