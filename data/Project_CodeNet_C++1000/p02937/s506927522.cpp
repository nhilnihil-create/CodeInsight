#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  string t;
  cin >> t;
  int N = s.size();
  int M = t.size();
  vector<set<int>> pos(26);
  for (int i = 0; i < N; i++){
    pos[s[i] - 'a'].insert(i);
  }
  bool ok = true;
  for (int i = 0; i < M; i++){
    if (pos[t[i] - 'a'].empty()){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    long long ans = -1;
    for (int i = 0; i < M; i++){
      auto itr = pos[t[i] - 'a'].upper_bound(ans % N);
      if (itr != pos[t[i] - 'a'].end()){
        ans += *itr - ans % N;
      } else {
        ans += N - ans % N;
        auto itr2 = pos[t[i] - 'a'].begin();
        ans += *itr2;
      }
    }
    cout << ans + 1 << endl;
  }
}