#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int kabuka[85];
  int n;
  cin >> n;
  REP(i, n) { cin >> kabuka[i]; }

  ll money = 1000;
  ll kabu = 0;
  REP(i, n - 1) {
    if (kabuka[i] < kabuka[i + 1]) {
      kabu = (money / kabuka[i]);
      money += (kabu * (kabuka[i + 1] - kabuka[i]));
    }
  }
  cout << money << endl;
}