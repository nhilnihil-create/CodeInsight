#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  int n; cin >> n; 
  vector<int> s(1<<n); REP(i, 1<<n) cin >> s[i];
  sort(s.begin(), s.end());

  vector<int> exist;
  exist.push_back(s.back());
  s.back() = -1;
  REP(i, n) {
    vector<int> tmp = exist;
    sort(tmp.begin(), tmp.end());
    int sidx = (1<<n)-1;
    while(tmp.size() && sidx >= 0) {
      if(s[sidx] == -1) { --sidx; continue; }
      if(tmp.back() > s[sidx]) {
        exist.push_back(s[sidx]);
        tmp.pop_back();
        s[sidx] = -1;
      }
      --sidx;
    }
    if(tmp.size()) {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes";
  return 0;
}