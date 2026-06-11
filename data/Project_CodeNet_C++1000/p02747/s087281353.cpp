#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;
const ll mod  = 1e9 + 7;
const int INF = 2e9;
using pint = pair <int, int>;

int main() {
  string s;
  cin >> s;
  int n    = s.length();
  bool ans = true;
  for (int i = 0; i < n; i += 2) {
	  if (s.substr(i, 2) != "hi") {
		  ans = false;
		}
	}
  if (ans) {
	  cout << "Yes" << endl;
	} else {
	  cout << "No" << endl;
	}
  return 0;
}
