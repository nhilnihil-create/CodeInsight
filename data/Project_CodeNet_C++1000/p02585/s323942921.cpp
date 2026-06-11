#include <bits/stdc++.h>
using namespace std;

int main(){
  size_t N,K;
  cin >> N >> K;

  vector<int> perm(N);
  for(size_t i=0; i<N; i++){
    cin >> perm.at(i);
    perm.at(i)--; // 1-indexed -> 0-indexed
  }

  vector<int64_t> data(N);
  for(size_t i=0; i<N; i++){
    cin >> data.at(i);
  }

  vector<int64_t> memo(N);
  for(size_t i=0; i<N; i++){
    vector<int64_t> memo_cycle;
    memo_cycle.emplace_back(0);
    size_t v= perm.at(i);
    int64_t cumsum= data.at(v);
    while(memo_cycle.size() < K && v != i){
      memo_cycle.emplace_back(cumsum);
      v= perm.at(v);
      cumsum+= data.at(v);
    }
    size_t Kcycle= memo_cycle.size();
    int64_t score_loop= cumsum;
    memo_cycle.emplace_back(score_loop);

    int64_t score_i= INT64_MIN;
    for(size_t r= 1; r<= Kcycle; r++){
      if(score_loop <= 0){
        score_i= max(score_i, memo_cycle.at(r));
      }
      else{
        int64_t cand= memo_cycle.at(r)+ score_loop* ((K-r)/Kcycle);
        score_i= max(score_i, cand);
      }
    }
    memo.at(i)= score_i;
  }

  int64_t ans= INT64_MIN;
  for(auto score:memo){
    ans= max(ans, score);
  }
  
  cout << ans << endl;
}