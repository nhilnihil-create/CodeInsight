#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcount(x)
#define all(x) x.begin(), x.end()
#define sz size()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mod 1000000007
#define ar array
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);

void init() {
  int n;
  cin >> n;
  vi a(n);
  for (int &i : a)
    cin >> i;
  vi l(n), r(n);
  l[0] = INT_MIN;
  r[n - 1] = INT_MIN;
  vi ans;
  for (int i = 1; i < n; i++)
    l[i] = max(l[i - 1], a[i - 1]);
  for (int i = n - 2; i >= 0; i--)
    r[i] = max(a[i + 1], r[i + 1]);
  for (int i = 0; i < n; i++)
    ans.push_back(max(l[i], r[i]));
  for(auto x:ans) cout<<x<<" ";
}
int32_t main() {
  IOS;
  init();
  return 0;
}
