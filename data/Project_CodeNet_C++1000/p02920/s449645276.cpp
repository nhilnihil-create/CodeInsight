#include<bits/stdc++.h>
using namespace std;

string solve() {
  int N;
  cin >> N;
  vector<int> S(pow(2,N));
  for(auto& i: S) cin >> i;

  multiset<int> s;
  for(auto i: S) s.emplace(-i);
  vector<int> q;
  q.emplace_back(*begin(s));
  s.erase(begin(s));
  for(auto sec=1; sec<=N; ++sec) {
    auto pre = q;
    for(auto x: pre) {
      auto i = s.upper_bound(x);
      if(i == end(s)) return "No";
      q.emplace_back(*i);
      s.erase(i);
    }
  }
  return "Yes";
}

int main() {
  cout << solve() << endl;
}
