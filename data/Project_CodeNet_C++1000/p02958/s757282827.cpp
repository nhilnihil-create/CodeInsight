#include<stdio.h>
#define size_t 100010
int main() {
 int n,a[size_t],i,count=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)  
  {
    scanf("%d",&a[i]);
  }  
  for(i=1;i<=n;i++)
  {
   if(a[i]!=i)
   { count++; }
  } 
  if(count<=2)
  {printf("YES\n");}
  else { printf("NO\n"); }
    return 0;
    }
    