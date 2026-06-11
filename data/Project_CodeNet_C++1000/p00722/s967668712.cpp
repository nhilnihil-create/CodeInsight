#include <stdio.h>
#include <math.h>

int main(void){
  unsigned int a, d, n;
  //unsigned int sosu[999999] = {0};
  unsigned int* sosu = new unsigned int[999999];
  unsigned int sosunum;

  unsigned int sqnum = (int)sqrt((double)999999);


  for(unsigned int i=0; i<999999; i++){
    sosu[i] = 1;
  }

  sosu[0] = 0;

  for(unsigned int i=1; i<sqnum; i++){
    if(sosu[i]==1){
      for(unsigned int j=i+1; (i+1)*j<=999999; j++){
	sosu[(i+1)*j-1] = 0;
      }
    }
  }

  while(1){
    sosunum = 0;
    scanf("%d%d%d", &a, &d, &n);
    if(a==0 && d==0 && n==0){
      break;
    }
    while(sosunum != n){
      if(sosu[a-1]){
	sosunum++;
      }
      a += d;
    }
    printf("%d\n", a-d);
  }
  return 0;
}