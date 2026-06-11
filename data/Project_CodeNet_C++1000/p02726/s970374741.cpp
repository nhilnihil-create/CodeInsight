#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  x--; y --;
  vector<int> ans(n);
  rep(i, n) {
    vector<int> dist(n, INF);
    queue<int> que;
    auto push = [&](int v, int d) {
      if (dist.at(v) != INF) return;
        
      dist.at(v) = d;
      que.push(v);
    };
    
    push(i, 0);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      int d = dist.at(v);
      
      if (v - 1 >= 0) push(v-1, d+1);
      if (v + 1 < n) push(v+1, d+1);
      if (v == x) push(y, d+1);
      if (v == y) push(x, d+1);
    }
    rep(i, n) ans.at(dist.at(i))++;
  }
  reps(i, 1, n) cout << ans.at(i)/2 << endl;
  
  return 0;
}