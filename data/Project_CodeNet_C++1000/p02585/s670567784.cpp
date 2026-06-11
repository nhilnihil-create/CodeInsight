#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K;
  cin >> N >> K;

  vector<int> perm(N);
  for(int i=0; i<N; i++){
    cin >> perm.at(i);
    perm.at(i)--; // 1-indexed -> 0-indexed
  }

  vector<int64_t> data(N);
  for(int i=0; i<N; i++){
    cin >> data.at(i);
  }

  int logK= 31- __builtin_clz(K);
  vector<vector<int>> trans(logK+1, vector<int>(N)); // trans.at(d).at(v): 頂点vから 2^d回操作したあとの遷移先
  trans.at(0)= perm;
  for(int d= 1; d<= logK; d++){
    for(int i=0; i<N; i++){
      trans.at(d).at(i)= trans.at(d-1).at(trans.at(d-1).at(i));
    }
  }
  
  vector<vector<int64_t>> sums(logK+1, vector<int64_t>(N)); // sums.at(d).at(v): 頂点vから 2^d回操作したあとのスコア
  vector<vector<int64_t>> cummaxs(logK+1, vector<int64_t>(N)); // cummaxs.at(d).at(v): 頂点vから 1回以上2^d回以下操作したあとの最大スコア
  for(int d=0; d<= logK; d++){
    for(int i=0; i<N; i++){
      sums.at(d).at(i)= (d > 0) ? sums.at(d-1).at(i)+ sums.at(d-1).at(trans.at(d-1).at(i))
                                : data.at(trans.at(0).at(i));
      cummaxs.at(d).at(i)= (d > 0) ? max(cummaxs.at(d-1).at(i), sums.at(d-1).at(i)+ cummaxs.at(d-1).at(trans.at(d-1).at(i)))
                                   : data.at(trans.at(0).at(i));
    }
  }

  vector<int64_t> memoK(N); // memoK.at(v): 頂点vから 1回以上K回以下操作したあとのスコアの最大値
  for(int i=0; i<N; i++){
    int64_t score_i= 0;
    int64_t walkthrough= 0;
    int v_walk= i;
    bool is_first= true;
    for(int d= logK; d>= 0; d--){
      if(K & (1<<d)){
        if(is_first){
          score_i= cummaxs.at(d).at(i);
          is_first= false;
        }
        else{
          score_i= max(score_i, walkthrough+ cummaxs.at(d).at(v_walk));
        }
        walkthrough+= sums.at(d).at(v_walk);
        v_walk= trans.at(d).at(v_walk);
      }
    }
    memoK.at(i)= score_i;
  }

  int64_t ans= INT64_MIN;
  for(auto score:memoK){
    ans= max(ans, score);
  }

  cout << ans << endl;
}