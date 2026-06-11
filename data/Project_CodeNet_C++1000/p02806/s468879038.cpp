#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  map<string, int> mp;
  vector<int> sum(n);
  rep(i, n) {
    string s;
    int a;
    cin >> s >> a;
    mp[s] = i;
    sum[i] = a;
    if (i)
      sum[i] += sum[i-1];
  }
  string s;
  cin >> s;
  int idx = mp[s];
  cout << sum[n-1]-sum[idx] << endl;
  return 0;
}