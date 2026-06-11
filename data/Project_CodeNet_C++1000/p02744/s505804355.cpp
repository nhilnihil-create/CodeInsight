#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int N;
void dfs(string s, char mx) {
  if (s.size() == N) {
    cout << s << endl;
  } else {
    for (char c = 'a'; c <= mx+1; c++) {
      char ma='a'-1;
      dfs(s + c, max(mx,c));
    }
  }
}
int main() {
  cin >> N;
  dfs("a", 'a');
}