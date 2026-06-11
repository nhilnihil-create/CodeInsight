#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ar array

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 2e5 + 5;

signed main(void)
{
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifdef LOCAL
    freopen("A.INP", "r", stdin);
    freopen("A.OUT", "w", stdout);
  #endif // LOCAL
  string s; cin >> s;
  cout << s.substr(0, 3);
}
