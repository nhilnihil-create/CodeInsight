#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 60);

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int res = 0;
  string t = s.substr(0, 1);
  for (int i = 0; i < n - 1; i++) {
    int j = 1;
    string cur = s.substr(i + 1, j);
    if (cur == t) {
      while (cur == t) j++, cur = s.substr(i, j);
      i += j - 1;
    }
    t = cur;
    res++;
    if (i == n - 2) res++;
  }
  cout << res << endl;
  return 0;
} 