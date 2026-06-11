#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define DD long double

#define MOD 1000000007
#define INF 1e18

void setIO(string s = "") { 
  cin.sync_with_stdio(0); cin.tie(0);
  if (s.size()) s += ".in", freopen(s.c_str(), "r", stdin);
}

bool cmp(pair<string, int>& a, pair<string, int>& b) { 
    return a.second < b.second; 
} 
  
int tt = 1;
void solve() {
  int n;
  string s;
  cin >> n;
  map<string, int> f;
  for (int i = 0; i < n; i++) {
    cin >> s;
    f[s]++;
  }

  if (f.size() == 1) {
    for (auto &it : f) cout << it.first << endl;
    return;
  }

  vector<pair<string, int>> vf;
  for (auto &it : f) vf.push_back(it);
  sort(vf.rbegin(), vf.rend(), cmp);
  set<string> top;
  top.insert(vf[0].first);
  for (int i = 1; i < vf.size(); i++) {
    if (vf[i].second < vf[i-1].second) break;
    else top.insert(vf[i].first);
  }

  for (auto it : top) {
    cout << it << endl;
  }

}

int main() {
  setIO();
  while (tt--) {
    solve();
  }
  return 0;
}