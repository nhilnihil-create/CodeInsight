#include <stdio.h>

int main(){
 long n,S[10000],q,T,cnt=0;

 scanf("%d",&n);
 for(int i=0;i<n;i++){
  scanf("%d",&S[i]);
 }
 scanf("%d",&q);
 for(int i=0;i<q;i++){
  scanf("%d",&T);
  for(int j=0;j<n;j++){
   if(T==S[j]){
    cnt++;
    break;
   }
  }
 }
 printf("%d\n",cnt);
 return 0;
}