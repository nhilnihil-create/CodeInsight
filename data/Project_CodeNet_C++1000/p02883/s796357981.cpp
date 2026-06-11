#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  int64_t K;
  cin >> N >> K;

  vector<int64_t> players(N);
  vector<int64_t> foods(N);
  for(int i=0; i<N; i++){
    cin >> players.at(i);
  }
  for(int i=0; i<N; i++){
    cin >> foods.at(i);
  }
  
  // 初期割当は以下に基づく：
  // a > 0, b1 > b2 > 0 => a* b1 > a* b2  
  sort(players.begin(), players.end());
  sort(foods.begin(), foods.end(), greater<int64_t>());

  // 二分探索で argmin v s.t. Nop(v) <= K を求める
  int64_t inc= 1LL << 40;
  int64_t exc= -1LL;
  while(abs(inc- exc) > 1){
    int64_t mid= (inc+ exc)/ 2;

    int64_t Kmid= 0;
    for(int i=0; i<N; i++){
      Kmid+= max(players.at(i)- mid/foods.at(i), int64_t(0));
    }

    if(Kmid <= K){ inc= mid; }
    else         { exc= mid; }
  }

  cout << inc << endl;
}