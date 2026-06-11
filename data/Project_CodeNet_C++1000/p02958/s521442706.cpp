#include <stdio.h>
int main()
{
  int X,k,cnt = 0;
  
  scanf("%d",&X);
 
  for(int i=1;i<=X;i++){
    scanf("%d" ,&k);
    if( k != i )
      cnt++;
  }
 
  if( cnt == 0 || cnt == 2)
    printf("YES\n");
  else
    printf("NO\n");
  
  return 0;
}