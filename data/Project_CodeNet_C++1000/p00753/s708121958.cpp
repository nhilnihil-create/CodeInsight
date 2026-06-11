#include<stdio.h>
#include<math.h>
#define N 10000000

int isprime(int);

int main(){
  int i,j;
  int count=0;
  int flag;
  int n;
  
  
  while(1){
    count=0;
    scanf("%d",&n);
    if(n==0)break;
    
    for(i=n+1;i<=2*n;i++){
      if(isprime(i)==1){
	count++;
      }   
    }
    printf("%d\n",count);
  }
  
  return 0;
}

int isprime(int x){
  int i=3;
  
  if(x==2) return 1;
  
  if(x<2||x%2==0)return 0;

  while(i<=sqrt(x)){
    if(x%i==0) return 0;
    i+=2;
  }

  return 1;
}