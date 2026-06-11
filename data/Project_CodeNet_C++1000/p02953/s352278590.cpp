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
  vi h(n);
  int mx = INT_MIN;
  for (int &i : h)
    cin >> i;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    mx = max(mx, h[i]);
    if (h[i] < mx - 1) {
      ok = false;
      break;
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
