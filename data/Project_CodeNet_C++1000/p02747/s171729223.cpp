#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

typedef long long int ll;
typedef pair<int, int> P;

const long long INF = 3e18 + 12;
const int inf = 1e9;

int main() {
  string s;
  cin >> s;

  string a = "hi";

  rep(i, 6) {
    if (s == a) {
      cout << "Yes" << endl;
      return 0;
    }

    a += "hi";
  }

  cout << "No" << endl;

  return 0;
}