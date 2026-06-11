#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n, m, q;
int ans = 0;

void debug_vector(vector<int> &vec) {
  cout << "[ ";
  REP(i, vec.size()) {
    cout << vec[i] << ", ";
  }
  cout << " ]";
}

void dfs(int s, int prev, vector<int> &seq, vector<vector<int>> & vec) {
  if (s == n) {
    int tmp = 0;
    REP(i, q) {
      int a = vec[i][0] - 1;
      int b = vec[i][1] - 1;
      if ((seq[b] - seq[a]) == vec[i][2])  {
        tmp += vec[i][3];
      }
    }
    ans = max(ans, tmp);
    return;
  }
  for (int i = prev; i <= m; i++) {
    seq[s] = i;
    dfs(s+1, i, seq, vec);
  }
}


int main()
{
  cin >> n >> m >> q;
  vector<vector<int>> vec;
  vector<int> seq(m, 0);
  REP(i, q) {
    vector<int> r(4, 0);
    REP(j, 4) {
      cin >> r[j];
    }
    vec.push_back(r);
  }
  dfs(0, 1, seq, vec);
  cout << ans << endl;
  return 0;
}