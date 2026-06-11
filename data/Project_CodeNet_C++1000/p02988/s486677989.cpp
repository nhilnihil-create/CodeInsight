#include <stdio.h>
int main()
{
  int r,count=0;
  scanf("%d",&r);
  int ar[r];
  for(int i=0;i<r;i++)
  {
    scanf("%d",&ar[i]);
  }
  for(int i=1;i<r-1;i++)
  {
    if(((ar[i-1]<ar[i])&&(ar[i]<ar[i+1]))||((ar[i-1]>ar[i])&&(ar[i]>ar[i+1])))
  {
    count++;
  }
  
  }
  printf("%d\n",count);
  return 0;
  }
  
    
   
 