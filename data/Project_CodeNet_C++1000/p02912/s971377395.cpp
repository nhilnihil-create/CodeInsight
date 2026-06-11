#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  int N, M;
  cin >> N >> M;
  vector<LL> A(N);
  for(auto& i: A) cin >> i;
  priority_queue<LL> q;
  for(auto i: A) q.emplace(i);
  for(auto i=0; i<M; ++i) {
    auto x = q.top(); q.pop();
    q.emplace(x/2);
  }
  LL s=0;
  while(!q.empty()) {s+=q.top(); q.pop();}
  cout << s << endl;
}
