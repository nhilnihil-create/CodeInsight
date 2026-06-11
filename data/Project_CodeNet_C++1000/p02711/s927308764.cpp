#include <stdio.h>
 
int main(){
 
 int B;
 scanf("%d", &B);
 
 if(B%10==7 || B/100==7 || B/10%10==7){
  
  puts("Yes");
  
 }else{
  
  puts ("No");
  
 }
}