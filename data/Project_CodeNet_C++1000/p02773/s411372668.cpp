#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;

signed main() {
  int n;
  cin >> n;

  map<string, int> mp;
  int maxv = 0;
  rep(i,n) {
    string s;
    cin >> s;
    mp[s]++;
    maxv = max(maxv, mp[s]);
  }

  vector<string> answer;
  for (auto it : mp) {
    if(it.second == maxv) {
      answer.push_back(it.first);
    }
  }
  sort(answer.begin(),answer.end());
  for (auto it : answer) {
    cout << it << '\n';
  }
  return 0;
}

