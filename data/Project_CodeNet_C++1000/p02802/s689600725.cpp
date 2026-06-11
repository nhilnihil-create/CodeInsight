#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
using ll = long long;

bool ac[MAX];
int wa[MAX];

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int p;
    string s;
    
    cin >> p >> s;

    if (ac[p]) continue;
  
    if (s == "AC") ac[p] = true;
    else ++wa[p];
  }

  int a = 0, w = 0;
  for (int i = 1; i <= n; ++i) {
    if (ac[i]) {
      ++a;
      w += wa[i];
    }
  }

  cout << a << " " << w << '\n';

  return (0);
}
