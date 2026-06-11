#include<bits/stdc++.h>
using namespace std;

int N, K, M = 0;
vector<vector<int>> G(110);

int main(){
	
  cin >> N >> K;

  if((N-1)*(N-2)/2 < K){ cout << -1 << endl; return 0; }  //中心頂点考慮

  int pair_n = (N-1)*(N-2)/2;

  for(int i = 2; i <= N; i++){ G[1].push_back(i); ++M; }

  for(int i = 2; i <= N; i++){
    for(int j = i+1; j <=N; j++){
      if(pair_n == K) break;
      G[i].push_back(j);
      pair_n -= 1;
      M += 1;
    }
    if(pair_n == K) break;
  }


  cout << M << endl;
  for(int i = 1; i <= N; i++){
    for(int j = 0; j < G[i].size(); j++) cout << i << " " << G[i][j] << endl;
  }

  return 0;

}
