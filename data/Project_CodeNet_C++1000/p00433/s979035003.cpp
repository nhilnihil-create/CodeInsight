#include<stdio.h>
int main(){
int a=0,b=0,d;
for(int i=0;i<4;i++){
 scanf("%d",&d);
 a=a+d;
}

for(int i=0;i<4;i++){
 scanf("%d",&d);
 b=b+d;
}
if(a<=b) printf("%d\n",b);
else printf("%d\n",a);
return 0;
}