#include<stdio.h>
int main()
{
  int i,j,k,l,cou,n;
  while(scanf("%d",&n)!=EOF){
    cou=0;
    for(i=0;i<=9;i++){
      for(j=0;j<=9;j++){
	for(k=0;k<=9;k++){
	  for(l=0;l<=9;l++){
	    if(i+j+k+l==n)cou++;
	  }
	}
      }
    }
    printf("%d\n",cou);
  }
  return 0;
}