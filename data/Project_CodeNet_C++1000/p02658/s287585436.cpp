#include <stdio.h>

int main(){

  long N,A[100000],i,x,a=1;

  

  scanf("%ld",&N);

  x=1;

  for(i=0;i<N;i++){

    scanf("%ld",&A[i]);

    if(A[i]==0){

      puts("0");

      return 0;

    }

    if((long)1e18/x/A[i]<1){

      a=0;

    }

    else x=x*A[i];

  }

  if(a==0)puts("-1");

  else printf("%ld\n",x);

  return 0;

}

