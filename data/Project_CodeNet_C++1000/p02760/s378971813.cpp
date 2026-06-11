#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int a[5][5];
int col[5][5], row[5][5];
int ld = 1, rd = 1;

signed main() {
#ifdef _DEBUG
  freopen("in" , "r", stdin );
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= 3; i++)
  for (int j = 1; j <= 3; j++) {
    cin >> a[i][j];
  }
  int n;
  cin >> n;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int t; cin >> t;
    s.insert(t);
  }
  int cnt = 0;
  for (int i = 1; i <= 3; i++) {
    col[0][i] = row[i][0] = 1;
  }
  for (int i = 1; i <= 3; i++)
  for (int j = 1; j <= 3; j++) {
    int t = 0;
    if (s.count(a[i][j])) {
      t = col[i][j] = row[i][j] = 1;
    }
    col[i][j] *= col[i - 1][j];
    row[i][j] *= row[i][j - 1];
    if (i - j == 0) ld *= t;
    if (i + j == 4) rd *= t;
    if (j == 3 && row[i][j] == 1) cnt++;
    if (i == 3 && col[i][j] == 1) cnt++;
  }
  if (ld) cnt++;
  if (rd) cnt++;
  if (cnt) cout << "Yes" << '\n';
  else cout << "No" << '\n';
}
