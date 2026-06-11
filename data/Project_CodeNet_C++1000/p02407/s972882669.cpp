#include<stdio.h>
#define N 100

int main(void){
  int a[N];
  int i,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i--;i>=0;i--){
    printf("%d",a[i]);
    if(i)putchar(' ');
    else putchar('\n');
  }
  return 0;
}