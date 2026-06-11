#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

const int N = 4e5;
vector<int> row[N];
int col[N];

void solve() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    row[x].push_back(y);
    col[y]++;
  }
  multiset<int, greater<int> > st;
  for (int y = 1; y <= m; y++) {
    st.insert(col[y]);
  }
  int ans = 0;
  for (int x = 1; x <= n; x++) {
    for (int y : row[x]) {
      st.erase(st.find(col[y]));
      col[y]--;
      st.insert(col[y]);
    }
    int res = *st.begin(), sz = row[x].size();
    ans = max(ans, res + sz);
    for (int y : row[x]) {
      st.erase(st.find(col[y]));
      col[y]++;
      st.insert(col[y]);
    }
  }
  cout << ans;
}

// CHECK LIMITS (n <= 10^5)
// CHECK CORNER CASES (n == 1)

int main() {
    ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    //cout << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    solve();
}
