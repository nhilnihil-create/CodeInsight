#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M, f = 0, kazu, keta;
  cin >> N >> M;
  vector<vector<int>> vec(M, vector<int>(2));
  for(int i = 0; i < M; i++){
    cin >> vec.at(i).at(0) >> vec.at(i).at(1);
    vec.at(i).at(0) = N - vec.at(i).at(0);
  }
  int kaihi;
  if(N == 1) kaihi = 0;
  else kaihi = pow(10, N - 1);
  for(int i = kaihi; i <= pow(10, N) -1; i++){
    for(int j = 0; j < M; j++){
      kazu = i;
      for(int k = 0; k < vec.at(j).at(0); k++){
        kazu /= 10;
      }
      keta = kazu % 10;
      if (keta != vec.at(j).at(1)){
        f = 1;
        break;
      }
    }
    if (f == 0){
      cout << i;
      return 0;
    }
    f = 0;
  }
  cout << -1;
}