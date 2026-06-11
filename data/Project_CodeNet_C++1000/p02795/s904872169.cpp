#include<cstdio>

using namespace std;

int main(){
  int H,N,W,A,L,n;
  scanf ("%d%d%d",&H,&W,&N);
  if (H > W){
  L = H;
  }else{
  L = W;
  }
   
  if (N % L == 0){
  n = N / L;
  }
  else{
  n = N / L + 1;
  }
  
  printf("%d\n",n);
  return 0;
}
  
  