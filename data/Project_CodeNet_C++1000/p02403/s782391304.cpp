#include <stdio.h>

int main(){
 int a, b, i, j, x;

 for(x=0; 1; x++){
  scanf("%d %d", &a, &b);
 
  if(a==0 && b==0){ break; }
 
  for(i = 0; i < a; i++){
   for(j = 0; j < b; j++){
     printf("#");
   }
   printf("\n");
  }
  
  printf("\n");
 }

 return 0;
}