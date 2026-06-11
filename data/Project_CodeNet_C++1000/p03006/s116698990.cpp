#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int,int>> loc(N);
  for (auto &p : loc) cin >> p.first >> p.second;
  sort(loc.begin(),loc.end());
  map<pair<int,int>,int> delt;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      int x = loc[j].first-loc[i].first;
      int y = loc[j].second-loc[i].second;
      delt[make_pair(x,y)] += 1;
    }
  }
  int M = 0;
  for (auto mp : delt) M = max(mp.second,M);
  cout << N-M << endl;
}