#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  map<int, vector<int>> jobs;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    jobs[M-a].push_back(b);
  }
  
  priority_queue<int> pq;
  long long ans = 0;
  for (int i = M; i >=0; i--) {
    for (auto j: jobs[i]) {
      pq.push(j);
    }

    if(!pq.empty()){
      ans += (long long)pq.top();
      pq.pop();
    }
  }
  
  cout << ans << endl;
  
  return 0;
  
}