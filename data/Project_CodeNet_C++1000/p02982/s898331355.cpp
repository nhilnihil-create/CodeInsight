#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N, D;
  cin >> N >> D;
  
  vector<vector<int>> vec(N, vector<int>(D));

  for (int i = 0; i < N; i++){
    for (int j = 0; j < D; j++){
      cin >> vec.at(i).at(j);
    }
  }

  int cnt = 0;
  double diff;
  for (int i = 0; i < N - 1; i++){
    for (int j = i + 1; j < N; j++){
      diff = 0;

      for (int k = 0; k < D; k++){
        diff += pow(vec.at(i).at(k) - vec.at(j).at(k), 2);
      }
      diff = sqrt(diff);
      if (floor(diff) == diff) cnt += 1;
    }
  }

  cout << cnt << endl;
}