#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  REP(t, b) {
    REP(i, a) cout << "0";
    REP(j, w - a) cout << "1";
    cout << endl;
  }
  REP(t, h - b) {
    REP(i, a) cout << "1";
    REP(j, w - a) cout << "0";
    cout << endl;
  }
}