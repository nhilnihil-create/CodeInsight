#include<stdio.h>
int main()
{
  int a,s,y,t;
  while(1){
    scanf("%d %d",&a,&s);
    if(a == 0 && s == 0)
      break;
    for(y=0;y<a;y++){
      for(t=0;t<s;t++){
        printf("#");
      }
      printf("\n");
        }
    printf("\n");
  }
  return 0;
}