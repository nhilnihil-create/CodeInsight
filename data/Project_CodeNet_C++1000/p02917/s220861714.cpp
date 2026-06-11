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
#define IOS                                                                    \
  std::ios::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);
void init() {
  int n;
  cin >> n;
  vi b(n - 1), a(n);
  for (int &i : b)
    cin >> i;
  int sum = 0;
  a[0] = b[0], a[n - 1] = b[n - 2];
  for (int i = 1; i < n - 1; i++)
    a[i] = min(b[i - 1], b[i]);
    // for(auto x:a) cout<<x<<" ";
  sum = accumulate(all(a), 0LL);
  cout << sum << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
