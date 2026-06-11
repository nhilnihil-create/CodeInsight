#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll INF = (1LL << 55);

int main(){ 
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<int> res;
  reverse(s.begin(), s.end());
  int cnt = -1;
  int prev = 0;
  for (int i = 0; i < n+1; i++) {
    int ng = s[i] - '0';
    cnt++;
    if (cnt <= m && !ng) prev = cnt;
    if (cnt == m) {
      if (prev == 0) {
        cout << -1 << endl;
        return 0;
      }
      res.emplace_back(prev);
      cnt -= prev;
      prev = 0;
    }
  }
  if (cnt != 0) res.emplace_back(cnt);
  reverse(res.begin(), res.end());
  for (auto e : res) cout << e << " ";
  cout << endl;
  return 0;
} 