#include "bits/stdc++.h"
using namespace std;
using lint = long long;
const int INF = 1e9;
typedef pair<lint, lint> P;

signed main(){
  lint N, D, A; cin >> N >> D >> A;
  vector<P> m(N);
  for(int i = 0; i < N; i++) cin >> m[i].first >> m[i].second;
  sort(m.begin(), m.end());
  queue<P> que;
  lint ans = 0, counter = 0;
  for(int i = 0; i < N; i++){
    while(que.size() && que.front().first < m[i].first){
      counter -= que.front().second;
      que.pop();
    }
    m[i].second -= counter * A;
    if(m[i].second < 0) continue;
    lint num = (m[i].second + A - 1) / A;
    ans += num; counter += num;
    que.push(P(m[i].first + 2 * D, num));
  }
  cout << ans << endl;
}