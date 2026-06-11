#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  pair<int,int> v[n];
  rep(i,n) {
    int a, b;
    cin >> a >> b;
    v[i] = make_pair(a, b);
  }
  sort(v, v+n);
  
  priority_queue<int> q; 
  int i = 0, s = 0;
  rep(j,m) {
    while(v[i].first == j+1) q.push(v[i].second), i++;
    if(!q.empty()) s += q.top(), q.pop();
  }
  cout << s << endl;
  return 0;
}