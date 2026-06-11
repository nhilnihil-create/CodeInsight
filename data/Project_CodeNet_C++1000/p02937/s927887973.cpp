#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin>>s>>t;
  map<char, set<int>> cm;
  for (int i=0; i<s.length(); i++) {
    cm[s[i]].insert(i);
  }
  long long cnt = 0;
  int idx = -1;
  for (char c: t) {
    if (cm[c].size() == 0) {
      cout<<-1<<endl;
      return 0;
    }
    auto it = cm[c].upper_bound(idx);
    if (it == cm[c].end()) {
      ++cnt;
      idx = *cm[c].begin();
    } else {
      idx = *it;
    }
  }
  cout<<cnt * s.length() + idx + 1<<endl;
}