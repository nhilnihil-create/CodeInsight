#include<bits/stdc++.h>
using namespace std;

int main(){
  int N , D ;
  cin >> N >> D;
  vector<vector<int>> x(N, vector<int>(D));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < D; j++)
      cin >> x[i][j]; 
  int ans = 0;
  for(int i = 0; i < N; i++){
    for(int k = i + 1; k < N; k++){
      int dist2 = 0;
      for(int j = 0; j < D; j++) dist2 += (x[i][j] - x[k][j]) * (x[i][j] - x[k][j]);
      int dist1 = sqrt(dist2); 
      if(dist2 == dist1 * dist1) ans++;
    }
  }
  cout << ans << endl;
}