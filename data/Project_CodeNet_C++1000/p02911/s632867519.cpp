#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, int> ipair;
#define int long long
#define pb push_back
#define ff first
#define INF INT_MAX
#define ss second
#define fr(i, j, a) for (int i = j; i < a; i++)
#define cnt_ones(x) __builtin_popcnt(x)
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vp vector<ipair>
#define mod 1000000007
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n, k, q;
  cin >> n >> k >> q;
  vi b(n, k);
  for (int i = 0; i < q; i++) {
    int p;
    cin >> p;
    --p;
    b[p]++;
  }
  for (auto &x : b)
    x -= q;
  for (auto x : b) {
    cout << ((x > 0) ? "Yes" : "No") << endl;
  }
}
int32_t main() {
  IOS;
  init();
  return 0;
}