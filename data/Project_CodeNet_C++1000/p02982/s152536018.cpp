#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int N, D;
  cin >> N >> D;
  int X[N][D];
  for (int i = 0; i < N; i++){
    for (int j = 0; j < D; j++){
      cin >> X[i][j];
    }
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      if(i != j){
        int s = 0;
        for (int k = 0; k < D; k++) s += (X[i][k] - X[j][k]) * (X[i][k] - X[j][k]);
        float ss = sqrt(s);
        if((float)((int)ss) == ss) ans++;
      }  
    }
    
  }
  
  printf("%d\n", ans);
}
