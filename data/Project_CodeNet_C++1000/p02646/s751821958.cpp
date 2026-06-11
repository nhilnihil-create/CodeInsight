#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;

int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if (abs(a - b) <= t * (v - w)) {
	  cout << "YES" << endl;
	} else {
	  cout << "NO" << endl;
	}
  return 0;
}
