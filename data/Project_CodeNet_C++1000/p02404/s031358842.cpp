#include <cstdio>
 
int main(){
int a,b;
while(true){
scanf("%d %d",&a,&b);
if(a==0) break;
for(int i=0;i<a;i++){
for(int j=0;j<b;j++){
 
if((i!=0)&&(j!=0)&&(i!=a-1)&&(j!=b-1))printf(".");
else printf("#");
 
}
printf("\n");
}
printf("\n");
}
return 0;
}