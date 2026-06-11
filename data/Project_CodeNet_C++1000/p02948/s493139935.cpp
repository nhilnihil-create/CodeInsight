#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;
  vector<vector<int>> W(M);
  for (int i = 0; i < N; i++){
    int A, B;
    cin >> A >> B;
    if (M - A >= 0){
      W[M - A].push_back(B);
    }
  }
  int ans = 0;
  priority_queue<int> pq;
  for (int i = M - 1; i >= 0; i--){
    for (int j : W[i]){
      pq.push(j);
    }
    if (!pq.empty()){
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}