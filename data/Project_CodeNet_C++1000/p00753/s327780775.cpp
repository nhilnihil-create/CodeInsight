#include<stdio.h>

int is_prime(int x){
  int i;
  for(i=2;i*i<=x;i++)
    {
      if(x%i==0)return 0;
    }
  return 1;
}

int main(void){
  int i,n,ans;
  while(scanf("%d",&n) && n)
    {
      ans = 0;
      for(i=n+1;i<=2*n;i++)
	{
	  if(is_prime(i))ans++;
	}
      printf("%d\n",ans);
    }
  return 0;
}