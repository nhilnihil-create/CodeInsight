#include<stdio.h>
int pr[50847534];

int x=0;
int nextpr(int p){
  int nxp=p+2;
  int i=0;
  int ok=0;
  pr[x]=p;
  x++;
  if(p==2)return 3;
  while(1==1){
    for(i=0;pr[i]*pr[i]<=nxp;i++){
      ok = 0;
      if(nxp%pr[i]==0){
        ok = 1;
        break;
      }
    }
    if(ok==0){
      return nxp;
    }else{
      nxp+=2;
    }
  }

}

int main(){
  int n,n2;
  int p=2;
  int done=0;
  scanf("%d",&n);
  printf("%d:",n);
  n2 = n;
  while(n>1){
    if(n%2==0){
      printf(" 2");
      n /= 2;
      done = 1;
    }else if(n%p==0){
      printf(" %d",p);
      n /= p;
      done = 1;
    }else{
      /*printf("X%d\n",p);*/
      p = nextpr(p);
    }
    if(p*p>n2&&done==0){
      printf(" %d",n2);
      break;
    }
  }
  printf("\n");
}