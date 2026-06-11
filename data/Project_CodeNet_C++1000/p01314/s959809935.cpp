#include <cstdio>

int main(void){
  int n, i, j, cnt, tmp;
  while(scanf("%d", &n)){
    if(n == 0){
      break;
    }
    cnt = 0;
    for(i=1; i<n/2+1; i++){
      for(j=i; j<n; j++){
        tmp = (i + j) * (j - i + 1) / 2;
        if(tmp == n){
          cnt++;
          break;
        }
        if(tmp > n){
          break;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

