#include <stdio.h>
#include <math.h>
int main(){
  int n,i,s;
  double a,m,heikin,heikin2,heikin22,s2,total=0,total2=0,result;
  while(1){
    scanf("%d",&n);
    if(n==0) break;
    else{
      for(i=1;i<=n;i++){
	scanf("%d",&s);
	total+=s;
	s2=s*s;
	total2+=s2;
      }
      heikin=total/n;
      
      heikin2=heikin*heikin;
      
      heikin22=total2/n;
     
      a=heikin22-heikin2;
     
      result=sqrt(a);
      printf("%f\n",result);
      total=0;
      total2=0;
    }
  }
  return 0;
}