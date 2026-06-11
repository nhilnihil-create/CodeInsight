#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin >> n;
  ll res = 0;
  map<string, int> table;
  rep(i, n) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    auto it = table.find(s);
    if (it != table.end()) {
      res += it->second;
      it->second++;
    } else {
      table[s] = 1;
    }
  }
  cout << res << endl;
  return 0;
}