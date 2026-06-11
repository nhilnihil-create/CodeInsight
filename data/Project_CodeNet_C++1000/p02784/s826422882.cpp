#include<stdio.h>
int main(){
   int h,n;
   scanf("%d%d",&h,&n);
   int a[n];
   int i,j;
   int tmp;
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++){
      h=h-a[i];
   }
   if(h<=0){
      printf("Yes");
   }else{
      printf("No");
   }
   return 0;
}
