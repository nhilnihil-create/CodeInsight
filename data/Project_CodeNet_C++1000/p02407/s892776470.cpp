#include <stdio.h>

int main(void)
{
  int n;
  int i;

  scanf("%d",&n);

  int ai[n];

  for(i=0; i<n; i++)
    scanf("%d",&ai[i]);

  for(i=(n-1); i>=0; i--){
    printf("%d",ai[i]);
    if(i>0)
      printf(" ");
  }
    
  puts("");
  
  return(0);
}