#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
typedef long long ll;
using namespace std;

class ab{
public:
  int a, b;
  bool operator<(const ab &another){
    if(b == another.b){
      return a < another.a;
    }
    return b < another.b;
  }
};

void solve(){
  int n, m; cin >> n >> m;
  vector<int> a(n), b(n);
  vector<vector<int> > v(m);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
    if(m - a[i] < 0) continue;
    v[m - a[i]].push_back(b[i]);
  }
  priority_queue<int> q;
  ll ans = 0;
  for(int i = m - 1; i >= 0; i--){
    for(int j = 0; j < v[i].size(); j++){
      q.push(v[i][j]);
    }
    if(!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;

  return;
}

int main(){
  solve();
  return 0;
}
