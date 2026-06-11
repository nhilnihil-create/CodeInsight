#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 前からと後ろから
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  vector<int> former;
  vector<int> latter;
  auto work = [&](string S, vector<int> v, bool rev){
    int cur = 0, cnt = 0;
    while (cur < N && cnt < K) {
      if (S[cur] == 'o') {
        if (rev) {
          v.push_back(N-1-cur);
        } else {
          v.push_back(cur);
        }
        cur += C+1;
        cnt++;
        continue;
      }
      cur++;
    }
    return v;
  };
  former = work(S, former, false);
  reverse(S.begin(), S.end());
  latter = work(S, latter, true);
  sort(latter.begin(), latter.end());
  rep(i, K) {
    if (former[i] == latter[i]) {
      cout << former[i]+1 << '\n';
    }
  }
  return 0;
}