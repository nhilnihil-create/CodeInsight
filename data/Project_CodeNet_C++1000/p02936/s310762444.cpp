#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e18;
int si[] = {-1, 0, 1, 0};
int sj[] = {0, -1, 0, 1};

vector<int> d(2*100000);
vector<int> p(2*100000,-1);
vector<vector<int>> r(2*100000, vector<int>(0));

void dfs(int i, int v) {
  d[i] += v;
  rep(j, r[i].size()){
    if (p[r[i][j]] == -1) {
      p[r[i][j]] = i;
      dfs(r[i][j], d[i]);
    }
  }
}

int main() {
  int n,q;
  cin >> n >> q;
  vector<int> a(n-1), b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    r[a[i]].push_back(b[i]);
    r[b[i]].push_back(a[i]);
  }

  rep(i,q) {
    int p, x;
    cin >> p >> x;
    d[p-1] += x;
  }

  p[0] = 0;
  dfs(0,0);
  rep(i,n) cout << d[i] << endl;

  return 0;
}
