#include <stdio.h>

int main(void){
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  int aa,bb;
  aa=(int)((float)a/0.08+0.9999);
  bb=(int)((float)b/0.1+0.9999);
  int m;
  if(aa>bb){
    m=aa;
  }else{
    m=bb;
  }
  if(((int)((float)m*0.08)==a) & ((int)((float)m*0.1)==b)){
    printf("%d",m);
  }else{
    printf("%d",-1);
  }
  return 0;
}