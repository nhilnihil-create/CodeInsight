
#include<stdio.h>
#define Num 100000
 
int a[Num];
int search(int c){
   if(c == a[c])
      return c;
   return a[c] = search(a[c]);
 }
int main(){
   int i,x,y,n,m,z;
   for(i=0;i<Num;i++){
      a[i] = i;
   }
   scanf("%d %d",&x,&y);
   for(i=0;i<y;i++){
      scanf("%d %d", &n,&m);
      if(search(n) != search(m)){
         a[search(m)] = search(n);
      }
   }
   scanf("%d",&z);
   for(i=0;i<z;i++){
      scanf("%d %d",&n,&m);
      if(search(n) == search(m))
         printf("yes\n");
      else
         printf("no\n");
   }
 
   return 0;
}