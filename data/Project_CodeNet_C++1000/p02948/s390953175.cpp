#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using P = pair<int, int>;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ab(m);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--;
    if (a < m) ab[a].push_back(b);
  }
  priority_queue<int> que;
  int ans = 0;
  rep(i, m){
    for(int x : ab[i]){
      que.push(x);
    }
    if (que.empty()) continue;
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
  
  return 0;
}