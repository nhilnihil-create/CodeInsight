#include<stdio.h>


bool isPrime(int n){
  if(n==1)return false;
  for(int i=2;i*i <= n;i++){
    if(n%i==0)return false;
  }
  return true;
}


int main(){
  
  int a,b,n;
  while(true){
    scanf("%d %d %d",&a,&b,&n);
    if(a==0 && b==0 && n==0 )return 0;
    
    for(int i=0;i<n;a+=b,i++){
      while(!isPrime(a)){a+=b;}
    }
    printf("%d\n",a-b);
    }
  //  int i;
  //scanf("%d",&i);
  //printf("%d\n",isPrime(i));
  return 0;
}