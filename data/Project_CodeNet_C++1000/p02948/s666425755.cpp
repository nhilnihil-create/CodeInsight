#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;

  vector<vector<int>> job(100001);
  for(int i=0; i<n; i++) {
    int a,b;
    cin>>a>>b;
    job[a].push_back(b);
  }

  int ans = 0;
  priority_queue<int, vector<int>, less<int>> work;
  for(int i=1; i<=m; i++) {
    for(int next: job[i]) {
      work.push(next);
    }
    if(!work.empty()) {
      ans += work.top();
      work.pop();
    }
  }

  cout<<ans<<endl;

  return 0;
}