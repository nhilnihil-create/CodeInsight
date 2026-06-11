#include<stdio.h>
#include<math.h>

int bruteforce(int N,int M,int a){
  int i;
  int b;
  b=a;
  if(M==1){
    if(-1<N||N<10){
      return 1;
    }
    else{
      return 0;
    }
  }
  else {
    M=M-1;
    for(i=fmax(N-M*9,0);i<=fmin(N,9);i++){
      a=a+bruteforce(N-i,M,b);
    }
  }

  return a;
}


int main(){
  int n;
  while(scanf("%d",&n)!=EOF){
    printf("%d\n",bruteforce(n,4,0));
  }

  return 0;
}