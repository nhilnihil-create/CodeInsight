#include <stdio.h>
int main(){
 
 int L,R,d;
 scanf("%d %d %d", &L, &R, &d);
 int akhir=0;
  for (int i=1; i<=R; i++){
   if(d*i >= L && d*i <= R){
    akhir++;
   }
  }
  printf("%d\n", akhir);
 return 0;
}