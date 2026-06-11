#include<cstdio>
#define LOOP(i,f,t) for(int i=f;i<=t;++i)
int main(){
  LOOP(i,1,9){
    LOOP(j,1,9){
      printf("%dx%d=%d\n",i,j,i*j);
    }
  }
}