#include <bits/stdc++.h>
using namespace std;
int LOG = 20;
int main(){
  string S;
  cin >> S;
  int N = S.size();
  vector<vector<int>> d(N, vector<int>(LOG));
  for (int i = 0; i < N; i++){
    if (S[i] == 'L'){
      d[i][0] = i - 1;
    } else {
      d[i][0] = i + 1;
    }
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < N; j++){
      d[j][i] = d[d[j][i - 1]][i - 1];
    }
  }
  vector<int> ans(N, 0);
  for (int i = 0; i < N; i++){
    ans[d[i][LOG - 1]]++;
  }
  for (int i = 0; i < N; i++){
    cout << ans[i];
    if (i < N - 1){
      cout << ' ';
    }
  }
  cout << endl;
}