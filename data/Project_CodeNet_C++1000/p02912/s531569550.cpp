#include <iostream>
#include <queue>

using namespace std;

#define int long long
#define rep(i,n) for(int i=0; i<(int)(n); i++)

signed main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> q;
  rep(i,n) {
    int a;
    cin >> a;
    q.push(a);
  }
  
  rep(i,m) {
    int a = q.top(); q.pop();
    q.push(a / 2);
  }
  
  int s = 0;
  while(!q.empty()) s += q.top(), q.pop();
  cout << s << endl;
  return 0;
}