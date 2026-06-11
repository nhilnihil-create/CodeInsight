#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;

  priority_queue<int, vector<int>, less<int>> prices;
  for(int i=0; i<n; i++) {
    int a;
    cin>>a;
    prices.push(a);
  }

  for(int i=0; i<m; i++) {
    int top = prices.top();
    prices.pop();
    prices.push(top/2);
  }

  int64_t ans = 0;
  while(!prices.empty()) {
    ans += prices.top();
    prices.pop();
  }

  cout<<ans<<endl;


  return 0;
}