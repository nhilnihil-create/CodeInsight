#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main() {
  int n;
  cin >> n;
  vector<pair<string, int>> t(n);
  rep(i,n) cin >> t[i].first >> t[i].second;
  string s;
  cin >> s;
  int res = 0;
  vector<int> cum(n+1,0);
  int idx = -1;
  for (int i = 0; i < n; i++) {
    cum[i+1] = cum[i] + t[i].second;
    if (t[i].first == s) idx = i;
  }
  cout << cum[n] - cum[idx+1] << endl;
  return 0;
} 