#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;
#define pint pair <int, int>
void dfs(string s, int sp, int n) {
  if (SZ(s) == n) {
	  cout << s << endl;
	  return;
	}
  REP(i, sp) {
	char c = 'a' + i;
	dfs(s + c, sp, n);
  }
  dfs(s + (char) ('a' + sp), sp + 1, n);
}

int main() {
  int n;
  cin >> n;
  dfs("", 0, n);
  return 0;
}
