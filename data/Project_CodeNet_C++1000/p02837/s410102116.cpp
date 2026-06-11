#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N;
  cin >> N;
  int state[N], max_s = 0, A[N];
  vector<pair<int, int> > testimony[N];
  for (int i = 0; i < N; i++){
    cin >> A[i];
    for (int j = 0; j < A[i]; j++){
      int x, y;
      cin >> x >> y;
      testimony[i].push_back(make_pair(x-1, y));
    }
  }
  
  for (int i = 0; i <(1<<N); i++){
    int flg = 0;
    for (int j = 0; j < N; j++){
      if (i & (1<<j)){
        state[j] = 1;
      }else{
        state[j] = 0;
      }
    }
    
    for (int j = 0; j < N; j++){
      if(state[j]==1){
        for (int k = 0; k < (int)testimony[j].size(); k++){
          int x = testimony[j][k].first, y = testimony[j][k].second; 
          if (state[x] != y){
            flg = 1;
            break;
          }
        }
      }
    }

    if(flg==0){
      int s = 0;
      for (int j = 0; j < N; j++){
        s += state[j];
      }
      if (s > max_s) max_s = s;
    }
  }

  printf("%d\n", max_s);
}
