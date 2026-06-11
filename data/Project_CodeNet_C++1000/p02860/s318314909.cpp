#include <stdio.h>
#include <string.h>

int main(){
 int i;
 scanf("%d", &i);
 
 char str[i+1];
 scanf("%s", &str);
 
 if (i%2!=0){
  printf("No\n");
 }
 else {
  int index=1;
  for (int n=0; n<i/2; n++){
   if (str[n]!=str[n+i/2]){
    index=0;
   }
  }
   if(index){
    printf("Yes\n");
   }
   else{
    printf("No\n");
   }
 }

 return 0;
}