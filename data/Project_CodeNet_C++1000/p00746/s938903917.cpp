#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

  while(1){
    int N;
    scanf("%d", &N);
    if(N == 0)
      break;

    int w = 1, h = 1;
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
    int x[1000] = {0}, y[1000] = {0};
    int dxm = 0, dxp = 0, dym = 0, dyp = 0;
    for(int i = 1; i < N; i++){
      int n, d;
      scanf("%d %d", &n, &d);
      x[i] = x[n] + dx[d];
      y[i] = y[n] + dy[d];
      dxm = min(x[i], dxm);
      dym = min(y[i], dym);
      dxp = max(x[i], dxp);
      dyp = max(y[i], dyp);
    }
    w += dxp - dxm;
    h += dyp - dym;
    
    printf("%d %d\n", w, h);
  }
  return 0;
}