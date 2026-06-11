#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N, D;
  scanf("%d %d", &N, &D);

  vector<int> xs(N), ys(N);
  for(int i=0;i<N;i++){
      scanf("%d %d", &xs[i], &ys[i]);
  }
  
  int S = 0;
  for(int i=0;i<N;i++){
    if( pow(xs[i],2) + pow(ys[i],2) <= pow(D, 2) ){
        S++;
    }
  }

  printf("%d\n", S);

  return 0;
}