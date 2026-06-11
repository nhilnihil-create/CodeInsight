#include <cstdio>
int main(){
 int in;
 int h=0,m=0,s=0;
 scanf("%d",&in);
 
 while(in>=3600){
 in -= 3600;
 h += 1;
 }

 while(in>=60){
 in -= 60;
 m += 1;
 }

 s = in;
 
 printf("%d:%d:%d\n",h,m,s);
}