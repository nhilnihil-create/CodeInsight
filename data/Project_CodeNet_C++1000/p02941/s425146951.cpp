#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;

  vector<int> A(N);
  for(auto& a: A){
    cin >> a;
  }
  vector<int> B(N);
  for(auto& b: B){
    cin >> b;
  }

  priority_queue<pair<int, int>> que;
  for(int i = 0; i < N; i++){
    que.push(make_pair(B[i], i));
  }

  long long ans = 0;
  while(!que.empty()){
    int top_idx = que.top().second;
    que.pop();

    int reducer = B[(top_idx + N - 1) % N] + B[(top_idx + 1) % N];
    if(reducer <= 0){
      continue;
    }

    int reduce_expected = B[top_idx] - A[top_idx];
    if(reduce_expected <= 0){
      continue;
    }

    int reduce_cnt = reduce_expected / reducer;
    if(reduce_cnt <= 0){
      continue;
    }
    B[top_idx] -= reduce_cnt * reducer;
    ans += reduce_cnt;
    que.push(make_pair(B[top_idx], top_idx));

    /*
    for(int i = 0; i < N; i++){
      cout << A[i] << ' ';
    }cout << endl;
    for(int i = 0; i < N; i++){
      cout << B[i] << ' ';
    }cout << endl;
    */
  }

  for(int i = 0; i < N; i++){
    if(A[i] != B[i]){
      ans = -1;
    }
  }

  cout << ans << endl;
}
