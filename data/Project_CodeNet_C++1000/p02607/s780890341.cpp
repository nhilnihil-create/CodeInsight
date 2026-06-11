#include <bits/stdc++.h>

#define rep(x, n) for(int i = x; i < (n); ++i)

using namespace std;
using ll = long long;

int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(1, n + 1) cin >> a[i];

  int res = 0;
  rep(1, (int)a.size()) if(i % 2 == 1 && a.at(i) % 2 == 1) ++res;
  cout << res << endl;
}