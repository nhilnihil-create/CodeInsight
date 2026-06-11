#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int n;
void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }
  for (char c = 'a'; c <= mx + 1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx, c));
  }
}

int main() {
  cin >> n;
  dfs("", 'a' - 1);
}