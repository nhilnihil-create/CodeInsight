#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef pair<int, int> P;

int n;
priority_queue<P> pq;
set<int> idxs;
long long ans;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    pq.push(P(p, i));
  }
  
  while (pq.size()) {
    int p = pq.top().first;
    int idx = pq.top().second;
    pq.pop();
    
    int w, x, y, z;
    w = x = -1;
    y = z = n;
    
    idxs.insert(idx);
    auto it = idxs.find(idx);
    
    if (it != idxs.begin()) {
      x = *prev(it);
      if (prev(it) != idxs.begin()) {
        w = *prev(it, 2);
      }
    }
    
    if (it != prev(idxs.end())) {
      y = *next(it);
      if (next(it) != prev(idxs.end())) {
        z = *next(it, 2);
      }
    }
    
    ans += p*((long long)(x-w)*(y-idx)+(idx-x)*(z-y));
  }
  
  cout << ans << endl;
  return 0;
}