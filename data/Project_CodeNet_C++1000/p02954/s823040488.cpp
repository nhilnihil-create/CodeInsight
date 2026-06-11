#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  string s;
  cin >> s;
  vector<int> ans(1e6);

  int i = 0;
  while (i < s.size()) {
    int current = i;
    int r_cnt = 0;
    int l_cnt = 0;
    while(s[i] == 'R') {
      r_cnt++;
      i++;
    }
    while(s[i] == 'L') {
      l_cnt++;
      i++;
    }

    int v = l_cnt + r_cnt;
    ans[current + r_cnt - 1] = v / 2;
    ans[current + r_cnt] = v / 2;
    if (v % 2 != 0) {
      if ((max(l_cnt, r_cnt) - 1) % 2 == 0) {
	if (l_cnt < r_cnt) {
	  ans[current + r_cnt - 1]++;
	} else {
	  ans[current + r_cnt]++;
	}
      } else {
	if (l_cnt < r_cnt) {
	  ans[current + r_cnt]++;
	} else {
	  ans[current + r_cnt - 1]++;
	}
      }
    }
  }

  for (int i = 0; i < s.size(); i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
