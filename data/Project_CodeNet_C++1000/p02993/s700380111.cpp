#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  char c = S.at(0);
  for (int i = 1; i < (int)S.length(); ++i) {
    if (c == S.at(i)) {
      cout << "Bad" << endl;
      return 0;
    }
    c = S.at(i);
  }

  cout << "Good" << endl;

  return 0;
}
