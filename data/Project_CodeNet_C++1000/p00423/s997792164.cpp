#include<stdio.h>
int main()
{
  int a,b,at,bt,k,i;
  while(1){
    scanf("%d",&k);
      if(k==0)break;
      at=0;
      bt=0;
      for(i=0;i<k;i++){
	scanf("%d %d",&a,&b);
	if(a>b)at+=a+b;
	else if(b>a)bt+=a+b;
	else {
	  bt+=b;
	  at+=a;
	}
      }
      printf("%d %d\n",at,bt);
    }
    return 0;
  }