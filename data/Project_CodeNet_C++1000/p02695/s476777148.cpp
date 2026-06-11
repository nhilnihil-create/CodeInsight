#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int n, m, q;
vector<int> a, b, c, d;
int ans = 0;

void dfs(vector<int> A) {
  if(A.size() == n + 1) {
    int tot = 0;
    rep(i, q) {
      if(A[b[i]] - A[a[i]] == c[i]) {
        tot += d[i];
      }
    }
    ans = max(tot, ans);
    return;
  }
  A.push_back(A.back());
  while(A.back() <= m) {
    dfs(A);
    A.back()++;
  }
}

int main() {
  cin >> n >> m >> q;
  a = b = c = d = vector<int>(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  dfs(vector<int>(1,1));
  cout << ans << endl;
  return 0;
}