#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = a; i < (b + a); i++)
#define W1 while (1)
#define COUT(x) cout << x << endl
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007
#define PB push_back
#define F first
#define S second

int main() {
  int n;
  string tmp;
  map<string,int> s;
  vector<string> ans;
  int maxcount = 0;
  cin >> n;
  rep(i, n) {
    cin >> tmp;
    s[tmp]++;
    maxcount = max(maxcount, s[tmp]);
  }
  for (auto i : s) {
    if (i.S == maxcount) ans.PB(i.F);
  }
  sort(ans.begin(), ans.end());
  rep(i, ans.size()) {
    COUT(ans[i]);
  }

  return 0;
}
