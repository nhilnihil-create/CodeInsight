// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n, m; cin >> n >> m;
  vector<int> H(n);
  loop(i,0,n) cin >> H[i];
  vector<set<int> > S(n);
  loop(i,0,m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    S[a].insert(b);
    S[b].insert(a);
  }
  
  int cnt = 0;
  loop(i,0,n) {
    if (S[i].size() == 0) {
      cnt++;
      continue;
    }
    
    int h = H[i];
    bool ok = true;
    for (auto&&v: S[i]) {
      ok &= h > H[v];
    }
    cnt += ok;
  }
  cout << cnt << endl;
  return 0;
}
