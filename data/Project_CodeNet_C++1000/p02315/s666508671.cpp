#include <iostream>
using namespace std;

int main(){
  int N,W;
  cin >> N >> W;
  int v[128],w[128];
  for(int i=1; i<=N; ++i){
    cin >> v[i] >> w[i];
  }

  int V[128][16384] = {};
  // ???????????????????????????
  for(int i=0; i<=127; ++i) V[i][0] = 0;
  for(int i=0; i<=16383; ++i) V[0][i] = 0;
    
  for(int i=1; i<=N; ++i){
    for(int c=1; c<=W; ++c){
      if(c-w[i] < 0){
        V[i][c] = V[i-1][c];
      } else {
        V[i][c] = max(V[i-1][c-w[i]]+v[i],V[i-1][c]);
      }
    }
  }

  cout << V[N][W] << endl;
}