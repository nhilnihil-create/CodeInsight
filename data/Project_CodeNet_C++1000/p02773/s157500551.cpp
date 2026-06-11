#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<string> Poll(N);
  for (int i = 0; i < N; i++) cin >> Poll[i];
  int cnt = 1;
  vector<pair<int, string>> res;
  sort(Poll.begin(), Poll.end());
  for (int i = 0; i < N-1; i++) {
    if (Poll[i] == Poll[i+1]) cnt++;
    else {
      res.push_back({cnt, Poll[i]});
      cnt = 1;
    }
  }
  res.push_back({cnt, Poll[N-1]});
  sort(res.begin(), res.end());
  int num = res.size()-1;
  for (int i = res.size()-1; i > 0; i--) {
    if (res[i].first == res[i-1].first) num--;
    else break;
  }
  for (int i = num; i < res.size(); i++) cout << res[i].second << endl;
}
