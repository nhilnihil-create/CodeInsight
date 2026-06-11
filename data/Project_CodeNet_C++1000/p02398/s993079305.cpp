#include<stdio.h>
//using namespace std;
//scanf("%d%d%d%d%d",&W,&H,&x,&y,&r);
//printf("Yes\n");
int main() {
  int a,b,c,N=1,X=0;
  scanf("%d%d%d",&a,&b,&c);
  
  while(N <= c){
    
    if(c%N == 0 && a <= N && N <= b){
      N=N+1;
      X=X+1;
    }else{
      N=N+1;
    }
  }  
 
 printf("%d\n",X);
}
