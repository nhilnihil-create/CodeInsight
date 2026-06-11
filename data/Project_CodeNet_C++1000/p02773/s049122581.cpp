#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  map<string,int> m;
  int max_cnt = 0;
  rep(i,n) {
    string s; cin >> s;
    m[s]++;
    max_cnt = max(m[s], max_cnt);
  }
  for (auto mi : m) {
    string k = mi.first;
    int v = mi.second;
    if (v == max_cnt) cout << k << endl;
  }
  return 0;
}
