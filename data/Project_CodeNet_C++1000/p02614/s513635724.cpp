#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
#define degreeToRadian(deg) (((deg)/360)*2*M_PI)
#define radianTodegree(rad) (((rad)/2/M_PI)*360)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
//cout << fixed << setprecision(15) << y << endl;
int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<char>> graph(h);
  int bcnt = 0;
  rep (i, h) {
    string s;
    cin >> s;
    for (auto v : s) {
      graph[i].push_back(v);
      if (v == '#') bcnt++;
    }
  }

  int ans = 0;
  rep (i, 1 << h) {
    rep (j, 1 << w) {
      int cnt = 0;
      vector<vector<char>> tmp = graph;
      
      rep (ii, h) {
	if (i & 1 << ii) {
	  rep (jjj, w) {
	    if (tmp[ii][jjj] == '#') cnt++;
	    tmp[ii][jjj] = 'x';
	  }
	}
      }

      rep (jj, w) {
	if (j & 1 << jj) {
	  rep (iii, h) {
	    if (tmp[iii][jj] == '#') cnt++;
	    tmp[iii][jj] = 'x';
	  }
	}
      }

      if (bcnt - cnt == k) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
