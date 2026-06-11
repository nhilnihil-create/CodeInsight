#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007

bool dbgflag = false;

struct edge {
  int color = -1;
  vector<int> to;
};

void dfs(int i, int col, vector<edge>&edges) {
  edges[i].color = col;
  int c = 1;
  for (int nx: edges[i].to) {
    if (c == col) c++;
    if (edges[nx].color == -1) {
      dfs(nx, c, edges);
      c++;
    }
  }
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(n+1);
  for (int i = 0; i < n; i++) cin >> a[i+1];
  for (int i = 1; i <= n; i++) a[i] += a[i-1];
  for (int i = 0; i <= n; i++) {
    a[i] -= (i) - k;
    a[i] %= k;
  }
  if (dbgflag) for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  if (dbgflag) cout << endl;  
  
  map<int, int> aCount;
  int left = 0, right = 0;
  ll cnt = 0;
  while (right - left != min(n+1, k)) {
    cnt += aCount[a[right]];
    aCount[a[right]]++;
    right++;
    if (dbgflag) cout << cnt << endl;
  }
  if (dbgflag) cout << "right: " << right << endl;
  while (right <= n) {
    aCount[a[left]]--;
    cnt += aCount[a[right]];
    aCount[a[right]]++;
    right++;
    left++;
    if (dbgflag) cout << cnt << endl;
  }
  cout << cnt << endl;
}
