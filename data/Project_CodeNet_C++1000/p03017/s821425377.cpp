#include <iostream>
#include <string>

using namespace std;

void failure () {
  cout << "No" << '\n';
  exit(0);
}

void success () {
  cout << "Yes" << '\n';
  exit(0);
}

const int MAX_N = 2e5 + 5;

int comp [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  a--; b--; c--; d--;

  string s;
  cin >> s;

  int hast = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || (i == 1 && s[i - 1] == '#') ||
        (i >= 2 && s[i - 1] == '#' && s[i - 2] == '#')) {
      comp[i] = i;
    } else {
      comp[i] = comp[i - 1];
    }

    if (i >= 2 && s[i] == '.' && s[i - 1] == '.' && s[i - 2] == '.') {
      if (comp[i] == comp[a] && b <= i - 1 && i - 1 <= d && i <= c) {
        hast = 1;
      }
    }
  }

  if (comp[a] != comp[c]) failure();
  if (comp[b] != comp[d]) failure();
  if (c > d && !hast) failure();
  success();
}
