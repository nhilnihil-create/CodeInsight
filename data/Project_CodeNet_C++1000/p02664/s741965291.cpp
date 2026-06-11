#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;

int main() {
  string t;
  cin >> t;
  REP(i, SZ(t)) {
	if (t[i] == '?') {
		t[i] = 'D';
	  }
  }
  cout << t << endl;
  return 0;
}
