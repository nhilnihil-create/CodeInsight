#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int score = 0;
  REP(i, n - 1) {
    if (s[i] == s[i + 1]) score++;
  }
  cout << min(score + 2 * k, n - 1) << endl;
}