#include <stdio.h>
int main()
{
  int N,p,a = 0;
  
  scanf("%d",&N);
 
  for(int i=1;i<=N;i++){
    scanf("%d" ,&p);
    if( p != i )
      a++;
  }
 
  if( a == 0 || a == 2)
    printf("YES\n");
  else
    printf("NO\n");
  
  return 0;
}