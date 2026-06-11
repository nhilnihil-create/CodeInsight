#include <stdio.h>
#include <math.h>

int gcd(int a, int b);

main(){
  int a,b,ans;
  scanf("%d%d",&a,&b);
  ans = gcd(a,b);
  printf("%d\n",ans);
  return 0;
}

int gcd(int a,int b)
{
  if(b==0){
    return a;
  }
  else{
    return gcd(b,a%b);
  }
}

