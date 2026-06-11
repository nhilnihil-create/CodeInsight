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
  map<vector<int>, int> mp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    vector<int> cnt(26);
    string s;
    cin >> s;
    sort(all(s));
    for (auto &x : s)
      cnt[x - 'a']++;
    mp[cnt]++;
  }
  for (auto p : mp) {
    int pp = p.second;
    ans += (pp * (pp - 1)) / 2;
  }
  cout << ans << endl;
}
int32_t main() {
  IOS;
  init();
  return 0;
}
